#!python

import mmap;
import re;

f=open("/usr/include/clang-c/Index.h", "r");
mm = mmap.mmap(f.fileno(), 0, access = mmap.ACCESS_READ);

enum1 = re.compile("typedef enum +?{([^ }]+)} ?([A-Za-z0-9_]*) ?;");
enum2 = re.compile("enum +([A-Za-z0-9_]+) *{([^}]*)}");
enumitem = re.compile("CX(([A-Za-z0-9_]+)([ \t\n]*=[ \t\n]*(([0-9]+)|(0x[0-9a-fA-F]+)|([A-Za-z0-9_]+)|(1 << [0-9]+)|(\(\(1 << 22\) - 1\))))?)(,|( ?\n))");

items = [];

for match in enum2.finditer(mm):
	item = {
		'name': match.group(1),
		'contents': match.group(2)
	};
	items.append(item);
	
for match in enum1.finditer(mm):
	item = {
		'name': match.group(2),
		'contents': match.group(1)
	};

	items.append(item);

for item in items:
	item['name'] = item['name'][2:];
	vals = [];
	for match in enumitem.finditer(item['contents']):
		nitem = {'name': match.group(2), 'value': match.group(4), 'unique': True};
		if nitem['value'] is not None and nitem['value'].startswith("CX"):
			nitem['value'] = nitem['value'][2:];
			nitem['unique'] = False;
			nitem['value'] = '_'.join(nitem['value'].split("_")[1:]);
		if nitem['name'] == 'Cursor_FirstRef':
			nitem['unique'] = False;
		nitem['orig'] = nitem['name'];
		nitem['name'] = '_'.join(nitem['name'].split("_")[1:]);
		vals.append(nitem);
	item['vals'] = vals;

for item in items:
	print '"', item['name'], '"';
	
f.close();

#Generate enum.h
f = open("enum.h", "w");

f.write('#pragma once\n\n');
f.write('#include <string>\n\n');
f.write('#include "exception.h"\n\n');
f.write('namespace clang {\n\n');

f.write('template <class T>\n');
f.write('std::string toString(T val);\n\n');

f.write('template <class T>\n');
f.write('T fromString(std::string val);\n\n');

for item in items:
	f.write('enum class ');
	f.write(item['name']);
	f.write(' {\n');
	for enumitem in item['vals']:
		f.write('\t');
		f.write(enumitem['name']);
		if enumitem['value'] is not None:
			f.write(' = ');
			f.write(enumitem['value']);
		f.write(',\n');
	f.write('};\n\n');

for item in items:
	f.write('template<>\n');
	f.write('inline ');
	f.write('std::string toString<');
	f.write(item['name']);
	f.write('>(');
	f.write(item['name']);
	f.write(' val) {\n');
	
	f.write('\tswitch(val) {\n');
	for enumitem in item['vals']:
		if enumitem['unique']:
			f.write('\t\tcase ');
		else:
			f.write('\t\t//case ');
		f.write(item['name']);
		f.write('::');
		f.write(enumitem['name']);
		f.write(': return "');
		f.write(enumitem['name']);
		f.write('";\n');
	f.write('\t\tdefault: throw InvalidEnumValueException<');
	f.write(item['name']);
	f.write('>(val);\n');
	f.write('\t}\n');
	f.write('}\n\n');
	
	f.write('template<>\n');
	f.write('inline ');
	f.write(item['name']);
	f.write(' fromString<');
	f.write(item['name']);
	f.write('>(');
	f.write('std::string val) {\n');
	
	f.write('\t');
	for enumitem in item['vals']:
		f.write('if(val == "');
		f.write(enumitem['name']);
		f.write('") return ');
		f.write(item['name']);
		f.write('::');
		f.write(enumitem['name']);
		f.write(';\n\telse ');
	f.write('throw InvalidStringValueException(val);\n');
	f.write('}\n\n');

f.write('}');

f.close();
