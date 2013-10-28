#!/bin/bash

CLASSES="$@"

for class in $CLASSES
do
	lower="$(tr [A-Z] [a-z] <<< "$class")"
	
	#cpp
	
	rm -f $lower.cpp
	
	echo '#include' "\"${lower}_internal.h\"" >> $lower.cpp
	echo '' >> $lower.cpp
	
	echo 'namespace clang {' >> $lower.cpp
	echo '' >> $lower.cpp
	
	echo "$class::$class(std::shared_ptr<${class}_> from) : p(from)" >> $lower.cpp
	echo '{' >> $lower.cpp
	echo '}' >> $lower.cpp
	echo '' >> $lower.cpp
	
	echo "$class::$class(${class}_* from) : p(from)" >> $lower.cpp
	echo '{' >> $lower.cpp
	echo '}' >> $lower.cpp
	echo '' >> $lower.cpp
	
	echo "$class::~$class()" >> $lower.cpp
	echo '{' >> $lower.cpp
	echo '}' >> $lower.cpp
	echo '' >> $lower.cpp
	
	echo '}' >> $lower.cpp
	
	#h
	
	rm -f $lower.h
	
	echo '#pragma once' >> $lower.h
	echo '' >> $lower.h
	
	echo '#include <memory>' >> $lower.h
	echo '' >> $lower.h
	
	echo 'namespace clang {' >> $lower.h
	echo '' >> $lower.h
	
	echo "class ${class}_;" >> $lower.h
	echo '' >> $lower.h
	echo "class $class {" >> $lower.h
	
	echo -e "\tpublic:" >> $lower.h
	echo -e "\t\t${class}() = delete;" >> $lower.h
	echo -e "\t\t${class}(const ${class}&) = default;" >> $lower.h
	echo -e "\t\t${class}& operator=(const ${class}&) = default;" >> $lower.h
	echo '' >>  $lower.h
	echo -e "\t\t$class(std::shared_ptr<${class}_> from);" >> $lower.h
	echo -e "\t\t$class(${class}_* from);" >> $lower.h
	echo '' >>  $lower.h
	echo -e "\t\t~$class();" >> $lower.h
	echo -e "\tprivate:" >> $lower.h
	echo -e "\t\tstd::shared_ptr<${class}_> p;" >> $lower.h
	echo -e '};' >> $lower.h
	
	echo '' >> $lower.h
	echo '}' >> $lower.h
	
	#internal
	
	rm -f ${lower}_internal.h
	
	echo '#pragma once' >> ${lower}_internal.h
	echo '' >> ${lower}_internal.h
	
	echo '#include <Index.h>' >> ${lower}_internal.h
	echo '' >> ${lower}_internal.h
	
	echo "#include \"$lower.h\"" >> ${lower}_internal.h
	echo '' >> ${lower}_internal.h
	
	echo 'namespace clang {' >> ${lower}_internal.h
	echo '' >> ${lower}_internal.h
	
	echo "class ${class}_ {" >> ${lower}_internal.h
	
	echo -e "\tpublic:" >> ${lower}_internal.h
	echo -e "\t\t${class}_() = delete;" >> ${lower}_internal.h
	echo -e "\t\t${class}_(const ${class}_&) = delete;" >> ${lower}_internal.h
	echo -e "\t\t${class}_& operator=(const ${class}_&) = delete;" >> ${lower}_internal.h
	echo '' >> ${lower}_internal.h
	echo -e "\t\t${class}_(const CX${class}& from) : $lower(from) {}" >> ${lower}_internal.h
	echo '' >> ${lower}_internal.h
	echo -e "\t\t~${class}_(){}" >> ${lower}_internal.h
	echo -e "\tprivate:" >> ${lower}_internal.h
	echo -e "\t\tCX${class} $lower;" >> ${lower}_internal.h
	echo -e '};' >> ${lower}_internal.h
	
	echo '' >> ${lower}_internal.h
	echo '}' >> ${lower}_internal.h
done
