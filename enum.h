#pragma once

#include <string>

#include "exception.h"

namespace clang {

template <class T>
std::string toString(T val);

template <class T>
T fromString(std::string val);

enum class AvailabilityKind {
	Available,
	Deprecated,
	NotAvailable,
	NotAccessible,
};

enum class DiagnosticSeverity {
	Ignored = 0,
	Note = 1,
	Warning = 2,
	Error = 3,
	Fatal = 4,
};

enum class LoadDiag_Error {
	None = 0,
	Unknown = 1,
	CannotLoad = 2,
	InvalidFile = 3,
};

enum class DiagnosticDisplayOptions {
	DisplaySourceLocation = 0x01,
	DisplayColumn = 0x02,
	DisplaySourceRanges = 0x04,
	DisplayOption = 0x08,
	DisplayCategoryId = 0x10,
	DisplayCategoryName = 0x20,
};

enum class TranslationUnit_Flags {
	None = 0x0,
	DetailedPreprocessingRecord = 0x01,
	Incomplete = 0x02,
	PrecompiledPreamble = 0x04,
	CacheCompletionResults = 0x08,
	ForSerialization = 0x10,
	CXXChainedPCH = 0x20,
	SkipFunctionBodies = 0x40,
	IncludeBriefCommentsInCodeCompletion = 0x80,
};

enum class SaveTranslationUnit_Flags {
	None = 0x0,
};

enum class SaveError {
	None = 0,
	Unknown = 1,
	TranslationErrors = 2,
	InvalidTU = 3,
};

enum class Reparse_Flags {
	None = 0x0,
};

enum class TUResourceUsageKind {
	AST = 1,
	Identifiers = 2,
	Selectors = 3,
	GlobalCompletionResults = 4,
	SourceManagerContentCache = 5,
	AST_SideTables = 6,
	SourceManager_Membuffer_Malloc = 7,
	SourceManager_Membuffer_MMap = 8,
	ExternalASTSource_Membuffer_Malloc = 9,
	ExternalASTSource_Membuffer_MMap = 10,
	Preprocessor = 11,
	PreprocessingRecord = 12,
	SourceManager_DataStructures = 13,
	Preprocessor_HeaderSearch = 14,
	MEMORY_IN_BYTES_BEGIN = AST,
	MEMORY_IN_BYTES_END = Preprocessor_HeaderSearch,
	First = AST,
	Last = Preprocessor_HeaderSearch,
};

enum class CursorKind {
	UnexposedDecl = 1,
	StructDecl = 2,
	UnionDecl = 3,
	ClassDecl = 4,
	EnumDecl = 5,
	FieldDecl = 6,
	EnumConstantDecl = 7,
	FunctionDecl = 8,
	VarDecl = 9,
	ParmDecl = 10,
	ObjCInterfaceDecl = 11,
	ObjCCategoryDecl = 12,
	ObjCProtocolDecl = 13,
	ObjCPropertyDecl = 14,
	ObjCIvarDecl = 15,
	ObjCInstanceMethodDecl = 16,
	ObjCClassMethodDecl = 17,
	ObjCImplementationDecl = 18,
	ObjCCategoryImplDecl = 19,
	TypedefDecl = 20,
	CXXMethod = 21,
	Namespace = 22,
	LinkageSpec = 23,
	Constructor = 24,
	Destructor = 25,
	ConversionFunction = 26,
	TemplateTypeParameter = 27,
	NonTypeTemplateParameter = 28,
	TemplateTemplateParameter = 29,
	FunctionTemplate = 30,
	ClassTemplate = 31,
	ClassTemplatePartialSpecialization = 32,
	NamespaceAlias = 33,
	UsingDirective = 34,
	UsingDeclaration = 35,
	TypeAliasDecl = 36,
	ObjCSynthesizeDecl = 37,
	ObjCDynamicDecl = 38,
	CXXAccessSpecifier = 39,
	FirstDecl = UnexposedDecl,
	LastDecl = CXXAccessSpecifier,
	FirstRef = 40,
	ObjCSuperClassRef = 40,
	ObjCProtocolRef = 41,
	ObjCClassRef = 42,
	TypeRef = 43,
	CXXBaseSpecifier = 44,
	TemplateRef = 45,
	NamespaceRef = 46,
	MemberRef = 47,
	LabelRef = 48,
	OverloadedDeclRef = 49,
	VariableRef = 50,
	LastRef = VariableRef,
	FirstInvalid = 70,
	InvalidFile = 70,
	NoDeclFound = 71,
	NotImplemented = 72,
	InvalidCode = 73,
	LastInvalid = InvalidCode,
	FirstExpr = 100,
	UnexposedExpr = 100,
	DeclRefExpr = 101,
	MemberRefExpr = 102,
	CallExpr = 103,
	ObjCMessageExpr = 104,
	BlockExpr = 105,
	IntegerLiteral = 106,
	FloatingLiteral = 107,
	ImaginaryLiteral = 108,
	StringLiteral = 109,
	CharacterLiteral = 110,
	ParenExpr = 111,
	UnaryOperator = 112,
	ArraySubscriptExpr = 113,
	BinaryOperator = 114,
	CompoundAssignOperator = 115,
	ConditionalOperator = 116,
	CStyleCastExpr = 117,
	CompoundLiteralExpr = 118,
	InitListExpr = 119,
	AddrLabelExpr = 120,
	StmtExpr = 121,
	GenericSelectionExpr = 122,
	GNUNullExpr = 123,
	CXXStaticCastExpr = 124,
	CXXDynamicCastExpr = 125,
	CXXReinterpretCastExpr = 126,
	CXXConstCastExpr = 127,
	CXXFunctionalCastExpr = 128,
	CXXTypeidExpr = 129,
	CXXBoolLiteralExpr = 130,
	CXXNullPtrLiteralExpr = 131,
	CXXThisExpr = 132,
	CXXThrowExpr = 133,
	CXXNewExpr = 134,
	CXXDeleteExpr = 135,
	UnaryExpr = 136,
	ObjCStringLiteral = 137,
	ObjCEncodeExpr = 138,
	ObjCSelectorExpr = 139,
	ObjCProtocolExpr = 140,
	ObjCBridgedCastExpr = 141,
	PackExpansionExpr = 142,
	SizeOfPackExpr = 143,
	LambdaExpr = 144,
	ObjCBoolLiteralExpr = 145,
	ObjCSelfExpr = 146,
	LastExpr = ObjCSelfExpr,
	FirstStmt = 200,
	UnexposedStmt = 200,
	LabelStmt = 201,
	CompoundStmt = 202,
	CaseStmt = 203,
	DefaultStmt = 204,
	IfStmt = 205,
	SwitchStmt = 206,
	WhileStmt = 207,
	DoStmt = 208,
	ForStmt = 209,
	GotoStmt = 210,
	IndirectGotoStmt = 211,
	ContinueStmt = 212,
	BreakStmt = 213,
	ReturnStmt = 214,
	GCCAsmStmt = 215,
	AsmStmt = GCCAsmStmt,
	ObjCAtTryStmt = 216,
	ObjCAtCatchStmt = 217,
	ObjCAtFinallyStmt = 218,
	ObjCAtThrowStmt = 219,
	ObjCAtSynchronizedStmt = 220,
	ObjCAutoreleasePoolStmt = 221,
	ObjCForCollectionStmt = 222,
	CXXCatchStmt = 223,
	CXXTryStmt = 224,
	CXXForRangeStmt = 225,
	SEHTryStmt = 226,
	SEHExceptStmt = 227,
	SEHFinallyStmt = 228,
	MSAsmStmt = 229,
	NullStmt = 230,
	DeclStmt = 231,
	LastStmt = DeclStmt,
	TranslationUnit = 300,
	FirstAttr = 400,
	UnexposedAttr = 400,
	IBActionAttr = 401,
	IBOutletAttr = 402,
	IBOutletCollectionAttr = 403,
	CXXFinalAttr = 404,
	CXXOverrideAttr = 405,
	AnnotateAttr = 406,
	AsmLabelAttr = 407,
	LastAttr = AsmLabelAttr,
	PreprocessingDirective = 500,
	MacroDefinition = 501,
	MacroExpansion = 502,
	MacroInstantiation = MacroExpansion,
	InclusionDirective = 503,
	FirstPreprocessing = PreprocessingDirective,
	LastPreprocessing = InclusionDirective,
	ModuleImportDecl = 600,
	FirstExtraDecl = ModuleImportDecl,
	LastExtraDecl = ModuleImportDecl,
};

enum class LinkageKind {
	Invalid,
	NoLinkage,
	Internal,
	UniqueExternal,
	External,
};

enum class LanguageKind {
	Invalid = 0,
	C,
	ObjC,
	CPlusPlus,
};

enum class TypeKind {
	Invalid = 0,
	Unexposed = 1,
	Void = 2,
	Bool = 3,
	Char_U = 4,
	UChar = 5,
	Char16 = 6,
	Char32 = 7,
	UShort = 8,
	UInt = 9,
	ULong = 10,
	ULongLong = 11,
	UInt128 = 12,
	Char_S = 13,
	SChar = 14,
	WChar = 15,
	Short = 16,
	Int = 17,
	Long = 18,
	LongLong = 19,
	Int128 = 20,
	Float = 21,
	Double = 22,
	LongDouble = 23,
	NullPtr = 24,
	Overload = 25,
	Dependent = 26,
	ObjCId = 27,
	ObjCClass = 28,
	ObjCSel = 29,
	FirstBuiltin = Void,
	LastBuiltin = ObjCSel,
	Complex = 100,
	Pointer = 101,
	BlockPointer = 102,
	LValueReference = 103,
	RValueReference = 104,
	Record = 105,
	Enum = 106,
	Typedef = 107,
	ObjCInterface = 108,
	ObjCObjectPointer = 109,
	FunctionNoProto = 110,
	FunctionProto = 111,
	ConstantArray = 112,
	Vector = 113,
};

enum class CallingConv {
	Default = 0,
	C = 1,
	X86StdCall = 2,
	X86FastCall = 3,
	X86ThisCall = 4,
	X86Pascal = 5,
	AAPCS = 6,
	AAPCS_VFP = 7,
	PnaclCall = 8,
	IntelOclBicc = 9,
	Invalid = 100,
	Unexposed = 200,
};

enum class TypeLayoutError {
};

enum class _CXXAccessSpecifier {
	CXXInvalidAccessSpecifier,
	CXXPublic,
	CXXProtected,
	CXXPrivate,
};

enum class ChildVisitResult {
	Break,
	Continue,
	Recurse,
};

enum class CommentKind {
	Null = 0,
	Text = 1,
	InlineCommand = 2,
	HTMLStartTag = 3,
	HTMLEndTag = 4,
	Paragraph = 5,
	BlockCommand = 6,
	ParamCommand = 7,
	TParamCommand = 8,
	VerbatimBlockCommand = 9,
	VerbatimBlockLine = 10,
	VerbatimLine = 11,
	FullComment = 12,
};

enum class CommentInlineCommandRenderKind {
	Normal,
	Bold,
	Monospaced,
	Emphasized,
};

enum class CommentParamPassDirection {
	In,
	Out,
	InOut,
};

enum class NameRefFlags {
	WantQualifier = 0x1,
	WantTemplateArgs = 0x2,
	WantSinglePiece = 0x4,
};

enum class TokenKind {
	Punctuation,
	Keyword,
	Identifier,
	Literal,
	Comment,
};

enum class CompletionChunkKind {
	Optional,
	TypedText,
	Text,
	Placeholder,
	Informative,
	CurrentParameter,
	LeftParen,
	RightParen,
	LeftBracket,
	RightBracket,
	LeftBrace,
	RightBrace,
	LeftAngle,
	RightAngle,
	Comma,
	ResultType,
	Colon,
	SemiColon,
	Equal,
	HorizontalSpace,
	VerticalSpace,
};

enum class CodeComplete_Flags {
	IncludeMacros = 0x01,
	IncludeCodePatterns = 0x02,
	IncludeBriefComments = 0x04,
};

enum class CompletionContext {
	Unexposed = 0,
	AnyType = 1 << 0,
	AnyValue = 1 << 1,
	ObjCObjectValue = 1 << 2,
	ObjCSelectorValue = 1 << 3,
	CXXClassTypeValue = 1 << 4,
	DotMemberAccess = 1 << 5,
	ArrowMemberAccess = 1 << 6,
	ObjCPropertyAccess = 1 << 7,
	EnumTag = 1 << 8,
	UnionTag = 1 << 9,
	StructTag = 1 << 10,
	ClassTag = 1 << 11,
	Namespace = 1 << 12,
	NestedNameSpecifier = 1 << 13,
	ObjCInterface = 1 << 14,
	ObjCProtocol = 1 << 15,
	ObjCCategory = 1 << 16,
	ObjCInstanceMessage = 1 << 17,
	ObjCClassMessage = 1 << 18,
	ObjCSelectorName = 1 << 19,
	MacroName = 1 << 20,
	NaturalLanguage = 1 << 21,
	Unknown = ((1 << 22) - 1),
};

enum class VisitorResult {
	Break,
	Continue,
};

template<>
inline std::string toString<AvailabilityKind>(AvailabilityKind val) {
	switch(val) {
		case AvailabilityKind::Available: return "Available";
		case AvailabilityKind::Deprecated: return "Deprecated";
		case AvailabilityKind::NotAvailable: return "NotAvailable";
		case AvailabilityKind::NotAccessible: return "NotAccessible";
		default: throw InvalidEnumValueException<AvailabilityKind>(val);
	}
}

template<>
inline AvailabilityKind fromString<AvailabilityKind>(std::string val) {
	if(val == "Available") return AvailabilityKind::Available;
	else if(val == "Deprecated") return AvailabilityKind::Deprecated;
	else if(val == "NotAvailable") return AvailabilityKind::NotAvailable;
	else if(val == "NotAccessible") return AvailabilityKind::NotAccessible;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<DiagnosticSeverity>(DiagnosticSeverity val) {
	switch(val) {
		case DiagnosticSeverity::Ignored: return "Ignored";
		case DiagnosticSeverity::Note: return "Note";
		case DiagnosticSeverity::Warning: return "Warning";
		case DiagnosticSeverity::Error: return "Error";
		case DiagnosticSeverity::Fatal: return "Fatal";
		default: throw InvalidEnumValueException<DiagnosticSeverity>(val);
	}
}

template<>
inline DiagnosticSeverity fromString<DiagnosticSeverity>(std::string val) {
	if(val == "Ignored") return DiagnosticSeverity::Ignored;
	else if(val == "Note") return DiagnosticSeverity::Note;
	else if(val == "Warning") return DiagnosticSeverity::Warning;
	else if(val == "Error") return DiagnosticSeverity::Error;
	else if(val == "Fatal") return DiagnosticSeverity::Fatal;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<LoadDiag_Error>(LoadDiag_Error val) {
	switch(val) {
		case LoadDiag_Error::None: return "None";
		case LoadDiag_Error::Unknown: return "Unknown";
		case LoadDiag_Error::CannotLoad: return "CannotLoad";
		case LoadDiag_Error::InvalidFile: return "InvalidFile";
		default: throw InvalidEnumValueException<LoadDiag_Error>(val);
	}
}

template<>
inline LoadDiag_Error fromString<LoadDiag_Error>(std::string val) {
	if(val == "None") return LoadDiag_Error::None;
	else if(val == "Unknown") return LoadDiag_Error::Unknown;
	else if(val == "CannotLoad") return LoadDiag_Error::CannotLoad;
	else if(val == "InvalidFile") return LoadDiag_Error::InvalidFile;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<DiagnosticDisplayOptions>(DiagnosticDisplayOptions val) {
	switch(val) {
		case DiagnosticDisplayOptions::DisplaySourceLocation: return "DisplaySourceLocation";
		case DiagnosticDisplayOptions::DisplayColumn: return "DisplayColumn";
		case DiagnosticDisplayOptions::DisplaySourceRanges: return "DisplaySourceRanges";
		case DiagnosticDisplayOptions::DisplayOption: return "DisplayOption";
		case DiagnosticDisplayOptions::DisplayCategoryId: return "DisplayCategoryId";
		case DiagnosticDisplayOptions::DisplayCategoryName: return "DisplayCategoryName";
		default: throw InvalidEnumValueException<DiagnosticDisplayOptions>(val);
	}
}

template<>
inline DiagnosticDisplayOptions fromString<DiagnosticDisplayOptions>(std::string val) {
	if(val == "DisplaySourceLocation") return DiagnosticDisplayOptions::DisplaySourceLocation;
	else if(val == "DisplayColumn") return DiagnosticDisplayOptions::DisplayColumn;
	else if(val == "DisplaySourceRanges") return DiagnosticDisplayOptions::DisplaySourceRanges;
	else if(val == "DisplayOption") return DiagnosticDisplayOptions::DisplayOption;
	else if(val == "DisplayCategoryId") return DiagnosticDisplayOptions::DisplayCategoryId;
	else if(val == "DisplayCategoryName") return DiagnosticDisplayOptions::DisplayCategoryName;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<TranslationUnit_Flags>(TranslationUnit_Flags val) {
	switch(val) {
		case TranslationUnit_Flags::None: return "None";
		case TranslationUnit_Flags::DetailedPreprocessingRecord: return "DetailedPreprocessingRecord";
		case TranslationUnit_Flags::Incomplete: return "Incomplete";
		case TranslationUnit_Flags::PrecompiledPreamble: return "PrecompiledPreamble";
		case TranslationUnit_Flags::CacheCompletionResults: return "CacheCompletionResults";
		case TranslationUnit_Flags::ForSerialization: return "ForSerialization";
		case TranslationUnit_Flags::CXXChainedPCH: return "CXXChainedPCH";
		case TranslationUnit_Flags::SkipFunctionBodies: return "SkipFunctionBodies";
		case TranslationUnit_Flags::IncludeBriefCommentsInCodeCompletion: return "IncludeBriefCommentsInCodeCompletion";
		default: throw InvalidEnumValueException<TranslationUnit_Flags>(val);
	}
}

template<>
inline TranslationUnit_Flags fromString<TranslationUnit_Flags>(std::string val) {
	if(val == "None") return TranslationUnit_Flags::None;
	else if(val == "DetailedPreprocessingRecord") return TranslationUnit_Flags::DetailedPreprocessingRecord;
	else if(val == "Incomplete") return TranslationUnit_Flags::Incomplete;
	else if(val == "PrecompiledPreamble") return TranslationUnit_Flags::PrecompiledPreamble;
	else if(val == "CacheCompletionResults") return TranslationUnit_Flags::CacheCompletionResults;
	else if(val == "ForSerialization") return TranslationUnit_Flags::ForSerialization;
	else if(val == "CXXChainedPCH") return TranslationUnit_Flags::CXXChainedPCH;
	else if(val == "SkipFunctionBodies") return TranslationUnit_Flags::SkipFunctionBodies;
	else if(val == "IncludeBriefCommentsInCodeCompletion") return TranslationUnit_Flags::IncludeBriefCommentsInCodeCompletion;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<SaveTranslationUnit_Flags>(SaveTranslationUnit_Flags val) {
	switch(val) {
		case SaveTranslationUnit_Flags::None: return "None";
		default: throw InvalidEnumValueException<SaveTranslationUnit_Flags>(val);
	}
}

template<>
inline SaveTranslationUnit_Flags fromString<SaveTranslationUnit_Flags>(std::string val) {
	if(val == "None") return SaveTranslationUnit_Flags::None;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<SaveError>(SaveError val) {
	switch(val) {
		case SaveError::None: return "None";
		case SaveError::Unknown: return "Unknown";
		case SaveError::TranslationErrors: return "TranslationErrors";
		case SaveError::InvalidTU: return "InvalidTU";
		default: throw InvalidEnumValueException<SaveError>(val);
	}
}

template<>
inline SaveError fromString<SaveError>(std::string val) {
	if(val == "None") return SaveError::None;
	else if(val == "Unknown") return SaveError::Unknown;
	else if(val == "TranslationErrors") return SaveError::TranslationErrors;
	else if(val == "InvalidTU") return SaveError::InvalidTU;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<Reparse_Flags>(Reparse_Flags val) {
	switch(val) {
		case Reparse_Flags::None: return "None";
		default: throw InvalidEnumValueException<Reparse_Flags>(val);
	}
}

template<>
inline Reparse_Flags fromString<Reparse_Flags>(std::string val) {
	if(val == "None") return Reparse_Flags::None;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<TUResourceUsageKind>(TUResourceUsageKind val) {
	switch(val) {
		case TUResourceUsageKind::AST: return "AST";
		case TUResourceUsageKind::Identifiers: return "Identifiers";
		case TUResourceUsageKind::Selectors: return "Selectors";
		case TUResourceUsageKind::GlobalCompletionResults: return "GlobalCompletionResults";
		case TUResourceUsageKind::SourceManagerContentCache: return "SourceManagerContentCache";
		case TUResourceUsageKind::AST_SideTables: return "AST_SideTables";
		case TUResourceUsageKind::SourceManager_Membuffer_Malloc: return "SourceManager_Membuffer_Malloc";
		case TUResourceUsageKind::SourceManager_Membuffer_MMap: return "SourceManager_Membuffer_MMap";
		case TUResourceUsageKind::ExternalASTSource_Membuffer_Malloc: return "ExternalASTSource_Membuffer_Malloc";
		case TUResourceUsageKind::ExternalASTSource_Membuffer_MMap: return "ExternalASTSource_Membuffer_MMap";
		case TUResourceUsageKind::Preprocessor: return "Preprocessor";
		case TUResourceUsageKind::PreprocessingRecord: return "PreprocessingRecord";
		case TUResourceUsageKind::SourceManager_DataStructures: return "SourceManager_DataStructures";
		case TUResourceUsageKind::Preprocessor_HeaderSearch: return "Preprocessor_HeaderSearch";
		//case TUResourceUsageKind::MEMORY_IN_BYTES_BEGIN: return "MEMORY_IN_BYTES_BEGIN";
		//case TUResourceUsageKind::MEMORY_IN_BYTES_END: return "MEMORY_IN_BYTES_END";
		//case TUResourceUsageKind::First: return "First";
		//case TUResourceUsageKind::Last: return "Last";
		default: throw InvalidEnumValueException<TUResourceUsageKind>(val);
	}
}

template<>
inline TUResourceUsageKind fromString<TUResourceUsageKind>(std::string val) {
	if(val == "AST") return TUResourceUsageKind::AST;
	else if(val == "Identifiers") return TUResourceUsageKind::Identifiers;
	else if(val == "Selectors") return TUResourceUsageKind::Selectors;
	else if(val == "GlobalCompletionResults") return TUResourceUsageKind::GlobalCompletionResults;
	else if(val == "SourceManagerContentCache") return TUResourceUsageKind::SourceManagerContentCache;
	else if(val == "AST_SideTables") return TUResourceUsageKind::AST_SideTables;
	else if(val == "SourceManager_Membuffer_Malloc") return TUResourceUsageKind::SourceManager_Membuffer_Malloc;
	else if(val == "SourceManager_Membuffer_MMap") return TUResourceUsageKind::SourceManager_Membuffer_MMap;
	else if(val == "ExternalASTSource_Membuffer_Malloc") return TUResourceUsageKind::ExternalASTSource_Membuffer_Malloc;
	else if(val == "ExternalASTSource_Membuffer_MMap") return TUResourceUsageKind::ExternalASTSource_Membuffer_MMap;
	else if(val == "Preprocessor") return TUResourceUsageKind::Preprocessor;
	else if(val == "PreprocessingRecord") return TUResourceUsageKind::PreprocessingRecord;
	else if(val == "SourceManager_DataStructures") return TUResourceUsageKind::SourceManager_DataStructures;
	else if(val == "Preprocessor_HeaderSearch") return TUResourceUsageKind::Preprocessor_HeaderSearch;
	else if(val == "MEMORY_IN_BYTES_BEGIN") return TUResourceUsageKind::MEMORY_IN_BYTES_BEGIN;
	else if(val == "MEMORY_IN_BYTES_END") return TUResourceUsageKind::MEMORY_IN_BYTES_END;
	else if(val == "First") return TUResourceUsageKind::First;
	else if(val == "Last") return TUResourceUsageKind::Last;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CursorKind>(CursorKind val) {
	switch(val) {
		case CursorKind::UnexposedDecl: return "UnexposedDecl";
		case CursorKind::StructDecl: return "StructDecl";
		case CursorKind::UnionDecl: return "UnionDecl";
		case CursorKind::ClassDecl: return "ClassDecl";
		case CursorKind::EnumDecl: return "EnumDecl";
		case CursorKind::FieldDecl: return "FieldDecl";
		case CursorKind::EnumConstantDecl: return "EnumConstantDecl";
		case CursorKind::FunctionDecl: return "FunctionDecl";
		case CursorKind::VarDecl: return "VarDecl";
		case CursorKind::ParmDecl: return "ParmDecl";
		case CursorKind::ObjCInterfaceDecl: return "ObjCInterfaceDecl";
		case CursorKind::ObjCCategoryDecl: return "ObjCCategoryDecl";
		case CursorKind::ObjCProtocolDecl: return "ObjCProtocolDecl";
		case CursorKind::ObjCPropertyDecl: return "ObjCPropertyDecl";
		case CursorKind::ObjCIvarDecl: return "ObjCIvarDecl";
		case CursorKind::ObjCInstanceMethodDecl: return "ObjCInstanceMethodDecl";
		case CursorKind::ObjCClassMethodDecl: return "ObjCClassMethodDecl";
		case CursorKind::ObjCImplementationDecl: return "ObjCImplementationDecl";
		case CursorKind::ObjCCategoryImplDecl: return "ObjCCategoryImplDecl";
		case CursorKind::TypedefDecl: return "TypedefDecl";
		case CursorKind::CXXMethod: return "CXXMethod";
		case CursorKind::Namespace: return "Namespace";
		case CursorKind::LinkageSpec: return "LinkageSpec";
		case CursorKind::Constructor: return "Constructor";
		case CursorKind::Destructor: return "Destructor";
		case CursorKind::ConversionFunction: return "ConversionFunction";
		case CursorKind::TemplateTypeParameter: return "TemplateTypeParameter";
		case CursorKind::NonTypeTemplateParameter: return "NonTypeTemplateParameter";
		case CursorKind::TemplateTemplateParameter: return "TemplateTemplateParameter";
		case CursorKind::FunctionTemplate: return "FunctionTemplate";
		case CursorKind::ClassTemplate: return "ClassTemplate";
		case CursorKind::ClassTemplatePartialSpecialization: return "ClassTemplatePartialSpecialization";
		case CursorKind::NamespaceAlias: return "NamespaceAlias";
		case CursorKind::UsingDirective: return "UsingDirective";
		case CursorKind::UsingDeclaration: return "UsingDeclaration";
		case CursorKind::TypeAliasDecl: return "TypeAliasDecl";
		case CursorKind::ObjCSynthesizeDecl: return "ObjCSynthesizeDecl";
		case CursorKind::ObjCDynamicDecl: return "ObjCDynamicDecl";
		case CursorKind::CXXAccessSpecifier: return "CXXAccessSpecifier";
		//case CursorKind::FirstDecl: return "FirstDecl";
		//case CursorKind::LastDecl: return "LastDecl";
		//case CursorKind::FirstRef: return "FirstRef";
		case CursorKind::ObjCSuperClassRef: return "ObjCSuperClassRef";
		case CursorKind::ObjCProtocolRef: return "ObjCProtocolRef";
		case CursorKind::ObjCClassRef: return "ObjCClassRef";
		case CursorKind::TypeRef: return "TypeRef";
		case CursorKind::CXXBaseSpecifier: return "CXXBaseSpecifier";
		case CursorKind::TemplateRef: return "TemplateRef";
		case CursorKind::NamespaceRef: return "NamespaceRef";
		case CursorKind::MemberRef: return "MemberRef";
		case CursorKind::LabelRef: return "LabelRef";
		case CursorKind::OverloadedDeclRef: return "OverloadedDeclRef";
		case CursorKind::VariableRef: return "VariableRef";
		//case CursorKind::LastRef: return "LastRef";
		//case CursorKind::FirstInvalid: return "FirstInvalid";
		case CursorKind::InvalidFile: return "InvalidFile";
		case CursorKind::NoDeclFound: return "NoDeclFound";
		case CursorKind::NotImplemented: return "NotImplemented";
		case CursorKind::InvalidCode: return "InvalidCode";
		//case CursorKind::LastInvalid: return "LastInvalid";
		//case CursorKind::FirstExpr: return "FirstExpr";
		case CursorKind::UnexposedExpr: return "UnexposedExpr";
		case CursorKind::DeclRefExpr: return "DeclRefExpr";
		case CursorKind::MemberRefExpr: return "MemberRefExpr";
		case CursorKind::CallExpr: return "CallExpr";
		case CursorKind::ObjCMessageExpr: return "ObjCMessageExpr";
		case CursorKind::BlockExpr: return "BlockExpr";
		case CursorKind::IntegerLiteral: return "IntegerLiteral";
		case CursorKind::FloatingLiteral: return "FloatingLiteral";
		case CursorKind::ImaginaryLiteral: return "ImaginaryLiteral";
		case CursorKind::StringLiteral: return "StringLiteral";
		case CursorKind::CharacterLiteral: return "CharacterLiteral";
		case CursorKind::ParenExpr: return "ParenExpr";
		case CursorKind::UnaryOperator: return "UnaryOperator";
		case CursorKind::ArraySubscriptExpr: return "ArraySubscriptExpr";
		case CursorKind::BinaryOperator: return "BinaryOperator";
		case CursorKind::CompoundAssignOperator: return "CompoundAssignOperator";
		case CursorKind::ConditionalOperator: return "ConditionalOperator";
		case CursorKind::CStyleCastExpr: return "CStyleCastExpr";
		case CursorKind::CompoundLiteralExpr: return "CompoundLiteralExpr";
		case CursorKind::InitListExpr: return "InitListExpr";
		case CursorKind::AddrLabelExpr: return "AddrLabelExpr";
		case CursorKind::StmtExpr: return "StmtExpr";
		case CursorKind::GenericSelectionExpr: return "GenericSelectionExpr";
		case CursorKind::GNUNullExpr: return "GNUNullExpr";
		case CursorKind::CXXStaticCastExpr: return "CXXStaticCastExpr";
		case CursorKind::CXXDynamicCastExpr: return "CXXDynamicCastExpr";
		case CursorKind::CXXReinterpretCastExpr: return "CXXReinterpretCastExpr";
		case CursorKind::CXXConstCastExpr: return "CXXConstCastExpr";
		case CursorKind::CXXFunctionalCastExpr: return "CXXFunctionalCastExpr";
		case CursorKind::CXXTypeidExpr: return "CXXTypeidExpr";
		case CursorKind::CXXBoolLiteralExpr: return "CXXBoolLiteralExpr";
		case CursorKind::CXXNullPtrLiteralExpr: return "CXXNullPtrLiteralExpr";
		case CursorKind::CXXThisExpr: return "CXXThisExpr";
		case CursorKind::CXXThrowExpr: return "CXXThrowExpr";
		case CursorKind::CXXNewExpr: return "CXXNewExpr";
		case CursorKind::CXXDeleteExpr: return "CXXDeleteExpr";
		case CursorKind::UnaryExpr: return "UnaryExpr";
		case CursorKind::ObjCStringLiteral: return "ObjCStringLiteral";
		case CursorKind::ObjCEncodeExpr: return "ObjCEncodeExpr";
		case CursorKind::ObjCSelectorExpr: return "ObjCSelectorExpr";
		case CursorKind::ObjCProtocolExpr: return "ObjCProtocolExpr";
		case CursorKind::ObjCBridgedCastExpr: return "ObjCBridgedCastExpr";
		case CursorKind::PackExpansionExpr: return "PackExpansionExpr";
		case CursorKind::SizeOfPackExpr: return "SizeOfPackExpr";
		case CursorKind::LambdaExpr: return "LambdaExpr";
		case CursorKind::ObjCBoolLiteralExpr: return "ObjCBoolLiteralExpr";
		case CursorKind::ObjCSelfExpr: return "ObjCSelfExpr";
		//case CursorKind::LastExpr: return "LastExpr";
		//case CursorKind::FirstStmt: return "FirstStmt";
		case CursorKind::UnexposedStmt: return "UnexposedStmt";
		case CursorKind::LabelStmt: return "LabelStmt";
		case CursorKind::CompoundStmt: return "CompoundStmt";
		case CursorKind::CaseStmt: return "CaseStmt";
		case CursorKind::DefaultStmt: return "DefaultStmt";
		case CursorKind::IfStmt: return "IfStmt";
		case CursorKind::SwitchStmt: return "SwitchStmt";
		case CursorKind::WhileStmt: return "WhileStmt";
		case CursorKind::DoStmt: return "DoStmt";
		case CursorKind::ForStmt: return "ForStmt";
		case CursorKind::GotoStmt: return "GotoStmt";
		case CursorKind::IndirectGotoStmt: return "IndirectGotoStmt";
		case CursorKind::ContinueStmt: return "ContinueStmt";
		case CursorKind::BreakStmt: return "BreakStmt";
		case CursorKind::ReturnStmt: return "ReturnStmt";
		case CursorKind::GCCAsmStmt: return "GCCAsmStmt";
		//case CursorKind::AsmStmt: return "AsmStmt";
		case CursorKind::ObjCAtTryStmt: return "ObjCAtTryStmt";
		case CursorKind::ObjCAtCatchStmt: return "ObjCAtCatchStmt";
		case CursorKind::ObjCAtFinallyStmt: return "ObjCAtFinallyStmt";
		case CursorKind::ObjCAtThrowStmt: return "ObjCAtThrowStmt";
		case CursorKind::ObjCAtSynchronizedStmt: return "ObjCAtSynchronizedStmt";
		case CursorKind::ObjCAutoreleasePoolStmt: return "ObjCAutoreleasePoolStmt";
		case CursorKind::ObjCForCollectionStmt: return "ObjCForCollectionStmt";
		case CursorKind::CXXCatchStmt: return "CXXCatchStmt";
		case CursorKind::CXXTryStmt: return "CXXTryStmt";
		case CursorKind::CXXForRangeStmt: return "CXXForRangeStmt";
		case CursorKind::SEHTryStmt: return "SEHTryStmt";
		case CursorKind::SEHExceptStmt: return "SEHExceptStmt";
		case CursorKind::SEHFinallyStmt: return "SEHFinallyStmt";
		case CursorKind::MSAsmStmt: return "MSAsmStmt";
		case CursorKind::NullStmt: return "NullStmt";
		case CursorKind::DeclStmt: return "DeclStmt";
		//case CursorKind::LastStmt: return "LastStmt";
		case CursorKind::TranslationUnit: return "TranslationUnit";
		//case CursorKind::FirstAttr: return "FirstAttr";
		case CursorKind::UnexposedAttr: return "UnexposedAttr";
		case CursorKind::IBActionAttr: return "IBActionAttr";
		case CursorKind::IBOutletAttr: return "IBOutletAttr";
		case CursorKind::IBOutletCollectionAttr: return "IBOutletCollectionAttr";
		case CursorKind::CXXFinalAttr: return "CXXFinalAttr";
		case CursorKind::CXXOverrideAttr: return "CXXOverrideAttr";
		case CursorKind::AnnotateAttr: return "AnnotateAttr";
		case CursorKind::AsmLabelAttr: return "AsmLabelAttr";
		//case CursorKind::LastAttr: return "LastAttr";
		case CursorKind::PreprocessingDirective: return "PreprocessingDirective";
		case CursorKind::MacroDefinition: return "MacroDefinition";
		case CursorKind::MacroExpansion: return "MacroExpansion";
		//case CursorKind::MacroInstantiation: return "MacroInstantiation";
		case CursorKind::InclusionDirective: return "InclusionDirective";
		//case CursorKind::FirstPreprocessing: return "FirstPreprocessing";
		//case CursorKind::LastPreprocessing: return "LastPreprocessing";
		case CursorKind::ModuleImportDecl: return "ModuleImportDecl";
		//case CursorKind::FirstExtraDecl: return "FirstExtraDecl";
		//case CursorKind::LastExtraDecl: return "LastExtraDecl";
		default: throw InvalidEnumValueException<CursorKind>(val);
	}
}

template<>
inline CursorKind fromString<CursorKind>(std::string val) {
	if(val == "UnexposedDecl") return CursorKind::UnexposedDecl;
	else if(val == "StructDecl") return CursorKind::StructDecl;
	else if(val == "UnionDecl") return CursorKind::UnionDecl;
	else if(val == "ClassDecl") return CursorKind::ClassDecl;
	else if(val == "EnumDecl") return CursorKind::EnumDecl;
	else if(val == "FieldDecl") return CursorKind::FieldDecl;
	else if(val == "EnumConstantDecl") return CursorKind::EnumConstantDecl;
	else if(val == "FunctionDecl") return CursorKind::FunctionDecl;
	else if(val == "VarDecl") return CursorKind::VarDecl;
	else if(val == "ParmDecl") return CursorKind::ParmDecl;
	else if(val == "ObjCInterfaceDecl") return CursorKind::ObjCInterfaceDecl;
	else if(val == "ObjCCategoryDecl") return CursorKind::ObjCCategoryDecl;
	else if(val == "ObjCProtocolDecl") return CursorKind::ObjCProtocolDecl;
	else if(val == "ObjCPropertyDecl") return CursorKind::ObjCPropertyDecl;
	else if(val == "ObjCIvarDecl") return CursorKind::ObjCIvarDecl;
	else if(val == "ObjCInstanceMethodDecl") return CursorKind::ObjCInstanceMethodDecl;
	else if(val == "ObjCClassMethodDecl") return CursorKind::ObjCClassMethodDecl;
	else if(val == "ObjCImplementationDecl") return CursorKind::ObjCImplementationDecl;
	else if(val == "ObjCCategoryImplDecl") return CursorKind::ObjCCategoryImplDecl;
	else if(val == "TypedefDecl") return CursorKind::TypedefDecl;
	else if(val == "CXXMethod") return CursorKind::CXXMethod;
	else if(val == "Namespace") return CursorKind::Namespace;
	else if(val == "LinkageSpec") return CursorKind::LinkageSpec;
	else if(val == "Constructor") return CursorKind::Constructor;
	else if(val == "Destructor") return CursorKind::Destructor;
	else if(val == "ConversionFunction") return CursorKind::ConversionFunction;
	else if(val == "TemplateTypeParameter") return CursorKind::TemplateTypeParameter;
	else if(val == "NonTypeTemplateParameter") return CursorKind::NonTypeTemplateParameter;
	else if(val == "TemplateTemplateParameter") return CursorKind::TemplateTemplateParameter;
	else if(val == "FunctionTemplate") return CursorKind::FunctionTemplate;
	else if(val == "ClassTemplate") return CursorKind::ClassTemplate;
	else if(val == "ClassTemplatePartialSpecialization") return CursorKind::ClassTemplatePartialSpecialization;
	else if(val == "NamespaceAlias") return CursorKind::NamespaceAlias;
	else if(val == "UsingDirective") return CursorKind::UsingDirective;
	else if(val == "UsingDeclaration") return CursorKind::UsingDeclaration;
	else if(val == "TypeAliasDecl") return CursorKind::TypeAliasDecl;
	else if(val == "ObjCSynthesizeDecl") return CursorKind::ObjCSynthesizeDecl;
	else if(val == "ObjCDynamicDecl") return CursorKind::ObjCDynamicDecl;
	else if(val == "CXXAccessSpecifier") return CursorKind::CXXAccessSpecifier;
	else if(val == "FirstDecl") return CursorKind::FirstDecl;
	else if(val == "LastDecl") return CursorKind::LastDecl;
	else if(val == "FirstRef") return CursorKind::FirstRef;
	else if(val == "ObjCSuperClassRef") return CursorKind::ObjCSuperClassRef;
	else if(val == "ObjCProtocolRef") return CursorKind::ObjCProtocolRef;
	else if(val == "ObjCClassRef") return CursorKind::ObjCClassRef;
	else if(val == "TypeRef") return CursorKind::TypeRef;
	else if(val == "CXXBaseSpecifier") return CursorKind::CXXBaseSpecifier;
	else if(val == "TemplateRef") return CursorKind::TemplateRef;
	else if(val == "NamespaceRef") return CursorKind::NamespaceRef;
	else if(val == "MemberRef") return CursorKind::MemberRef;
	else if(val == "LabelRef") return CursorKind::LabelRef;
	else if(val == "OverloadedDeclRef") return CursorKind::OverloadedDeclRef;
	else if(val == "VariableRef") return CursorKind::VariableRef;
	else if(val == "LastRef") return CursorKind::LastRef;
	else if(val == "FirstInvalid") return CursorKind::FirstInvalid;
	else if(val == "InvalidFile") return CursorKind::InvalidFile;
	else if(val == "NoDeclFound") return CursorKind::NoDeclFound;
	else if(val == "NotImplemented") return CursorKind::NotImplemented;
	else if(val == "InvalidCode") return CursorKind::InvalidCode;
	else if(val == "LastInvalid") return CursorKind::LastInvalid;
	else if(val == "FirstExpr") return CursorKind::FirstExpr;
	else if(val == "UnexposedExpr") return CursorKind::UnexposedExpr;
	else if(val == "DeclRefExpr") return CursorKind::DeclRefExpr;
	else if(val == "MemberRefExpr") return CursorKind::MemberRefExpr;
	else if(val == "CallExpr") return CursorKind::CallExpr;
	else if(val == "ObjCMessageExpr") return CursorKind::ObjCMessageExpr;
	else if(val == "BlockExpr") return CursorKind::BlockExpr;
	else if(val == "IntegerLiteral") return CursorKind::IntegerLiteral;
	else if(val == "FloatingLiteral") return CursorKind::FloatingLiteral;
	else if(val == "ImaginaryLiteral") return CursorKind::ImaginaryLiteral;
	else if(val == "StringLiteral") return CursorKind::StringLiteral;
	else if(val == "CharacterLiteral") return CursorKind::CharacterLiteral;
	else if(val == "ParenExpr") return CursorKind::ParenExpr;
	else if(val == "UnaryOperator") return CursorKind::UnaryOperator;
	else if(val == "ArraySubscriptExpr") return CursorKind::ArraySubscriptExpr;
	else if(val == "BinaryOperator") return CursorKind::BinaryOperator;
	else if(val == "CompoundAssignOperator") return CursorKind::CompoundAssignOperator;
	else if(val == "ConditionalOperator") return CursorKind::ConditionalOperator;
	else if(val == "CStyleCastExpr") return CursorKind::CStyleCastExpr;
	else if(val == "CompoundLiteralExpr") return CursorKind::CompoundLiteralExpr;
	else if(val == "InitListExpr") return CursorKind::InitListExpr;
	else if(val == "AddrLabelExpr") return CursorKind::AddrLabelExpr;
	else if(val == "StmtExpr") return CursorKind::StmtExpr;
	else if(val == "GenericSelectionExpr") return CursorKind::GenericSelectionExpr;
	else if(val == "GNUNullExpr") return CursorKind::GNUNullExpr;
	else if(val == "CXXStaticCastExpr") return CursorKind::CXXStaticCastExpr;
	else if(val == "CXXDynamicCastExpr") return CursorKind::CXXDynamicCastExpr;
	else if(val == "CXXReinterpretCastExpr") return CursorKind::CXXReinterpretCastExpr;
	else if(val == "CXXConstCastExpr") return CursorKind::CXXConstCastExpr;
	else if(val == "CXXFunctionalCastExpr") return CursorKind::CXXFunctionalCastExpr;
	else if(val == "CXXTypeidExpr") return CursorKind::CXXTypeidExpr;
	else if(val == "CXXBoolLiteralExpr") return CursorKind::CXXBoolLiteralExpr;
	else if(val == "CXXNullPtrLiteralExpr") return CursorKind::CXXNullPtrLiteralExpr;
	else if(val == "CXXThisExpr") return CursorKind::CXXThisExpr;
	else if(val == "CXXThrowExpr") return CursorKind::CXXThrowExpr;
	else if(val == "CXXNewExpr") return CursorKind::CXXNewExpr;
	else if(val == "CXXDeleteExpr") return CursorKind::CXXDeleteExpr;
	else if(val == "UnaryExpr") return CursorKind::UnaryExpr;
	else if(val == "ObjCStringLiteral") return CursorKind::ObjCStringLiteral;
	else if(val == "ObjCEncodeExpr") return CursorKind::ObjCEncodeExpr;
	else if(val == "ObjCSelectorExpr") return CursorKind::ObjCSelectorExpr;
	else if(val == "ObjCProtocolExpr") return CursorKind::ObjCProtocolExpr;
	else if(val == "ObjCBridgedCastExpr") return CursorKind::ObjCBridgedCastExpr;
	else if(val == "PackExpansionExpr") return CursorKind::PackExpansionExpr;
	else if(val == "SizeOfPackExpr") return CursorKind::SizeOfPackExpr;
	else if(val == "LambdaExpr") return CursorKind::LambdaExpr;
	else if(val == "ObjCBoolLiteralExpr") return CursorKind::ObjCBoolLiteralExpr;
	else if(val == "ObjCSelfExpr") return CursorKind::ObjCSelfExpr;
	else if(val == "LastExpr") return CursorKind::LastExpr;
	else if(val == "FirstStmt") return CursorKind::FirstStmt;
	else if(val == "UnexposedStmt") return CursorKind::UnexposedStmt;
	else if(val == "LabelStmt") return CursorKind::LabelStmt;
	else if(val == "CompoundStmt") return CursorKind::CompoundStmt;
	else if(val == "CaseStmt") return CursorKind::CaseStmt;
	else if(val == "DefaultStmt") return CursorKind::DefaultStmt;
	else if(val == "IfStmt") return CursorKind::IfStmt;
	else if(val == "SwitchStmt") return CursorKind::SwitchStmt;
	else if(val == "WhileStmt") return CursorKind::WhileStmt;
	else if(val == "DoStmt") return CursorKind::DoStmt;
	else if(val == "ForStmt") return CursorKind::ForStmt;
	else if(val == "GotoStmt") return CursorKind::GotoStmt;
	else if(val == "IndirectGotoStmt") return CursorKind::IndirectGotoStmt;
	else if(val == "ContinueStmt") return CursorKind::ContinueStmt;
	else if(val == "BreakStmt") return CursorKind::BreakStmt;
	else if(val == "ReturnStmt") return CursorKind::ReturnStmt;
	else if(val == "GCCAsmStmt") return CursorKind::GCCAsmStmt;
	else if(val == "AsmStmt") return CursorKind::AsmStmt;
	else if(val == "ObjCAtTryStmt") return CursorKind::ObjCAtTryStmt;
	else if(val == "ObjCAtCatchStmt") return CursorKind::ObjCAtCatchStmt;
	else if(val == "ObjCAtFinallyStmt") return CursorKind::ObjCAtFinallyStmt;
	else if(val == "ObjCAtThrowStmt") return CursorKind::ObjCAtThrowStmt;
	else if(val == "ObjCAtSynchronizedStmt") return CursorKind::ObjCAtSynchronizedStmt;
	else if(val == "ObjCAutoreleasePoolStmt") return CursorKind::ObjCAutoreleasePoolStmt;
	else if(val == "ObjCForCollectionStmt") return CursorKind::ObjCForCollectionStmt;
	else if(val == "CXXCatchStmt") return CursorKind::CXXCatchStmt;
	else if(val == "CXXTryStmt") return CursorKind::CXXTryStmt;
	else if(val == "CXXForRangeStmt") return CursorKind::CXXForRangeStmt;
	else if(val == "SEHTryStmt") return CursorKind::SEHTryStmt;
	else if(val == "SEHExceptStmt") return CursorKind::SEHExceptStmt;
	else if(val == "SEHFinallyStmt") return CursorKind::SEHFinallyStmt;
	else if(val == "MSAsmStmt") return CursorKind::MSAsmStmt;
	else if(val == "NullStmt") return CursorKind::NullStmt;
	else if(val == "DeclStmt") return CursorKind::DeclStmt;
	else if(val == "LastStmt") return CursorKind::LastStmt;
	else if(val == "TranslationUnit") return CursorKind::TranslationUnit;
	else if(val == "FirstAttr") return CursorKind::FirstAttr;
	else if(val == "UnexposedAttr") return CursorKind::UnexposedAttr;
	else if(val == "IBActionAttr") return CursorKind::IBActionAttr;
	else if(val == "IBOutletAttr") return CursorKind::IBOutletAttr;
	else if(val == "IBOutletCollectionAttr") return CursorKind::IBOutletCollectionAttr;
	else if(val == "CXXFinalAttr") return CursorKind::CXXFinalAttr;
	else if(val == "CXXOverrideAttr") return CursorKind::CXXOverrideAttr;
	else if(val == "AnnotateAttr") return CursorKind::AnnotateAttr;
	else if(val == "AsmLabelAttr") return CursorKind::AsmLabelAttr;
	else if(val == "LastAttr") return CursorKind::LastAttr;
	else if(val == "PreprocessingDirective") return CursorKind::PreprocessingDirective;
	else if(val == "MacroDefinition") return CursorKind::MacroDefinition;
	else if(val == "MacroExpansion") return CursorKind::MacroExpansion;
	else if(val == "MacroInstantiation") return CursorKind::MacroInstantiation;
	else if(val == "InclusionDirective") return CursorKind::InclusionDirective;
	else if(val == "FirstPreprocessing") return CursorKind::FirstPreprocessing;
	else if(val == "LastPreprocessing") return CursorKind::LastPreprocessing;
	else if(val == "ModuleImportDecl") return CursorKind::ModuleImportDecl;
	else if(val == "FirstExtraDecl") return CursorKind::FirstExtraDecl;
	else if(val == "LastExtraDecl") return CursorKind::LastExtraDecl;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<LinkageKind>(LinkageKind val) {
	switch(val) {
		case LinkageKind::Invalid: return "Invalid";
		case LinkageKind::NoLinkage: return "NoLinkage";
		case LinkageKind::Internal: return "Internal";
		case LinkageKind::UniqueExternal: return "UniqueExternal";
		case LinkageKind::External: return "External";
		default: throw InvalidEnumValueException<LinkageKind>(val);
	}
}

template<>
inline LinkageKind fromString<LinkageKind>(std::string val) {
	if(val == "Invalid") return LinkageKind::Invalid;
	else if(val == "NoLinkage") return LinkageKind::NoLinkage;
	else if(val == "Internal") return LinkageKind::Internal;
	else if(val == "UniqueExternal") return LinkageKind::UniqueExternal;
	else if(val == "External") return LinkageKind::External;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<LanguageKind>(LanguageKind val) {
	switch(val) {
		case LanguageKind::Invalid: return "Invalid";
		case LanguageKind::C: return "C";
		case LanguageKind::ObjC: return "ObjC";
		case LanguageKind::CPlusPlus: return "CPlusPlus";
		default: throw InvalidEnumValueException<LanguageKind>(val);
	}
}

template<>
inline LanguageKind fromString<LanguageKind>(std::string val) {
	if(val == "Invalid") return LanguageKind::Invalid;
	else if(val == "C") return LanguageKind::C;
	else if(val == "ObjC") return LanguageKind::ObjC;
	else if(val == "CPlusPlus") return LanguageKind::CPlusPlus;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<TypeKind>(TypeKind val) {
	switch(val) {
		case TypeKind::Invalid: return "Invalid";
		case TypeKind::Unexposed: return "Unexposed";
		case TypeKind::Void: return "Void";
		case TypeKind::Bool: return "Bool";
		case TypeKind::Char_U: return "Char_U";
		case TypeKind::UChar: return "UChar";
		case TypeKind::Char16: return "Char16";
		case TypeKind::Char32: return "Char32";
		case TypeKind::UShort: return "UShort";
		case TypeKind::UInt: return "UInt";
		case TypeKind::ULong: return "ULong";
		case TypeKind::ULongLong: return "ULongLong";
		case TypeKind::UInt128: return "UInt128";
		case TypeKind::Char_S: return "Char_S";
		case TypeKind::SChar: return "SChar";
		case TypeKind::WChar: return "WChar";
		case TypeKind::Short: return "Short";
		case TypeKind::Int: return "Int";
		case TypeKind::Long: return "Long";
		case TypeKind::LongLong: return "LongLong";
		case TypeKind::Int128: return "Int128";
		case TypeKind::Float: return "Float";
		case TypeKind::Double: return "Double";
		case TypeKind::LongDouble: return "LongDouble";
		case TypeKind::NullPtr: return "NullPtr";
		case TypeKind::Overload: return "Overload";
		case TypeKind::Dependent: return "Dependent";
		case TypeKind::ObjCId: return "ObjCId";
		case TypeKind::ObjCClass: return "ObjCClass";
		case TypeKind::ObjCSel: return "ObjCSel";
		//case TypeKind::FirstBuiltin: return "FirstBuiltin";
		//case TypeKind::LastBuiltin: return "LastBuiltin";
		case TypeKind::Complex: return "Complex";
		case TypeKind::Pointer: return "Pointer";
		case TypeKind::BlockPointer: return "BlockPointer";
		case TypeKind::LValueReference: return "LValueReference";
		case TypeKind::RValueReference: return "RValueReference";
		case TypeKind::Record: return "Record";
		case TypeKind::Enum: return "Enum";
		case TypeKind::Typedef: return "Typedef";
		case TypeKind::ObjCInterface: return "ObjCInterface";
		case TypeKind::ObjCObjectPointer: return "ObjCObjectPointer";
		case TypeKind::FunctionNoProto: return "FunctionNoProto";
		case TypeKind::FunctionProto: return "FunctionProto";
		case TypeKind::ConstantArray: return "ConstantArray";
		case TypeKind::Vector: return "Vector";
		default: throw InvalidEnumValueException<TypeKind>(val);
	}
}

template<>
inline TypeKind fromString<TypeKind>(std::string val) {
	if(val == "Invalid") return TypeKind::Invalid;
	else if(val == "Unexposed") return TypeKind::Unexposed;
	else if(val == "Void") return TypeKind::Void;
	else if(val == "Bool") return TypeKind::Bool;
	else if(val == "Char_U") return TypeKind::Char_U;
	else if(val == "UChar") return TypeKind::UChar;
	else if(val == "Char16") return TypeKind::Char16;
	else if(val == "Char32") return TypeKind::Char32;
	else if(val == "UShort") return TypeKind::UShort;
	else if(val == "UInt") return TypeKind::UInt;
	else if(val == "ULong") return TypeKind::ULong;
	else if(val == "ULongLong") return TypeKind::ULongLong;
	else if(val == "UInt128") return TypeKind::UInt128;
	else if(val == "Char_S") return TypeKind::Char_S;
	else if(val == "SChar") return TypeKind::SChar;
	else if(val == "WChar") return TypeKind::WChar;
	else if(val == "Short") return TypeKind::Short;
	else if(val == "Int") return TypeKind::Int;
	else if(val == "Long") return TypeKind::Long;
	else if(val == "LongLong") return TypeKind::LongLong;
	else if(val == "Int128") return TypeKind::Int128;
	else if(val == "Float") return TypeKind::Float;
	else if(val == "Double") return TypeKind::Double;
	else if(val == "LongDouble") return TypeKind::LongDouble;
	else if(val == "NullPtr") return TypeKind::NullPtr;
	else if(val == "Overload") return TypeKind::Overload;
	else if(val == "Dependent") return TypeKind::Dependent;
	else if(val == "ObjCId") return TypeKind::ObjCId;
	else if(val == "ObjCClass") return TypeKind::ObjCClass;
	else if(val == "ObjCSel") return TypeKind::ObjCSel;
	else if(val == "FirstBuiltin") return TypeKind::FirstBuiltin;
	else if(val == "LastBuiltin") return TypeKind::LastBuiltin;
	else if(val == "Complex") return TypeKind::Complex;
	else if(val == "Pointer") return TypeKind::Pointer;
	else if(val == "BlockPointer") return TypeKind::BlockPointer;
	else if(val == "LValueReference") return TypeKind::LValueReference;
	else if(val == "RValueReference") return TypeKind::RValueReference;
	else if(val == "Record") return TypeKind::Record;
	else if(val == "Enum") return TypeKind::Enum;
	else if(val == "Typedef") return TypeKind::Typedef;
	else if(val == "ObjCInterface") return TypeKind::ObjCInterface;
	else if(val == "ObjCObjectPointer") return TypeKind::ObjCObjectPointer;
	else if(val == "FunctionNoProto") return TypeKind::FunctionNoProto;
	else if(val == "FunctionProto") return TypeKind::FunctionProto;
	else if(val == "ConstantArray") return TypeKind::ConstantArray;
	else if(val == "Vector") return TypeKind::Vector;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CallingConv>(CallingConv val) {
	switch(val) {
		case CallingConv::Default: return "Default";
		case CallingConv::C: return "C";
		case CallingConv::X86StdCall: return "X86StdCall";
		case CallingConv::X86FastCall: return "X86FastCall";
		case CallingConv::X86ThisCall: return "X86ThisCall";
		case CallingConv::X86Pascal: return "X86Pascal";
		case CallingConv::AAPCS: return "AAPCS";
		case CallingConv::AAPCS_VFP: return "AAPCS_VFP";
		case CallingConv::PnaclCall: return "PnaclCall";
		case CallingConv::IntelOclBicc: return "IntelOclBicc";
		case CallingConv::Invalid: return "Invalid";
		case CallingConv::Unexposed: return "Unexposed";
		default: throw InvalidEnumValueException<CallingConv>(val);
	}
}

template<>
inline CallingConv fromString<CallingConv>(std::string val) {
	if(val == "Default") return CallingConv::Default;
	else if(val == "C") return CallingConv::C;
	else if(val == "X86StdCall") return CallingConv::X86StdCall;
	else if(val == "X86FastCall") return CallingConv::X86FastCall;
	else if(val == "X86ThisCall") return CallingConv::X86ThisCall;
	else if(val == "X86Pascal") return CallingConv::X86Pascal;
	else if(val == "AAPCS") return CallingConv::AAPCS;
	else if(val == "AAPCS_VFP") return CallingConv::AAPCS_VFP;
	else if(val == "PnaclCall") return CallingConv::PnaclCall;
	else if(val == "IntelOclBicc") return CallingConv::IntelOclBicc;
	else if(val == "Invalid") return CallingConv::Invalid;
	else if(val == "Unexposed") return CallingConv::Unexposed;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<TypeLayoutError>(TypeLayoutError val) {
	switch(val) {
		default: throw InvalidEnumValueException<TypeLayoutError>(val);
	}
}

template<>
inline TypeLayoutError fromString<TypeLayoutError>(std::string val) {
	throw InvalidStringValueException(val);
}

template<>
inline std::string toString<_CXXAccessSpecifier>(_CXXAccessSpecifier val) {
	switch(val) {
		case _CXXAccessSpecifier::CXXInvalidAccessSpecifier: return "CXXInvalidAccessSpecifier";
		case _CXXAccessSpecifier::CXXPublic: return "CXXPublic";
		case _CXXAccessSpecifier::CXXProtected: return "CXXProtected";
		case _CXXAccessSpecifier::CXXPrivate: return "CXXPrivate";
		default: throw InvalidEnumValueException<_CXXAccessSpecifier>(val);
	}
}

template<>
inline _CXXAccessSpecifier fromString<_CXXAccessSpecifier>(std::string val) {
	if(val == "CXXInvalidAccessSpecifier") return _CXXAccessSpecifier::CXXInvalidAccessSpecifier;
	else if(val == "CXXPublic") return _CXXAccessSpecifier::CXXPublic;
	else if(val == "CXXProtected") return _CXXAccessSpecifier::CXXProtected;
	else if(val == "CXXPrivate") return _CXXAccessSpecifier::CXXPrivate;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<ChildVisitResult>(ChildVisitResult val) {
	switch(val) {
		case ChildVisitResult::Break: return "Break";
		case ChildVisitResult::Continue: return "Continue";
		case ChildVisitResult::Recurse: return "Recurse";
		default: throw InvalidEnumValueException<ChildVisitResult>(val);
	}
}

template<>
inline ChildVisitResult fromString<ChildVisitResult>(std::string val) {
	if(val == "Break") return ChildVisitResult::Break;
	else if(val == "Continue") return ChildVisitResult::Continue;
	else if(val == "Recurse") return ChildVisitResult::Recurse;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CommentKind>(CommentKind val) {
	switch(val) {
		case CommentKind::Null: return "Null";
		case CommentKind::Text: return "Text";
		case CommentKind::InlineCommand: return "InlineCommand";
		case CommentKind::HTMLStartTag: return "HTMLStartTag";
		case CommentKind::HTMLEndTag: return "HTMLEndTag";
		case CommentKind::Paragraph: return "Paragraph";
		case CommentKind::BlockCommand: return "BlockCommand";
		case CommentKind::ParamCommand: return "ParamCommand";
		case CommentKind::TParamCommand: return "TParamCommand";
		case CommentKind::VerbatimBlockCommand: return "VerbatimBlockCommand";
		case CommentKind::VerbatimBlockLine: return "VerbatimBlockLine";
		case CommentKind::VerbatimLine: return "VerbatimLine";
		case CommentKind::FullComment: return "FullComment";
		default: throw InvalidEnumValueException<CommentKind>(val);
	}
}

template<>
inline CommentKind fromString<CommentKind>(std::string val) {
	if(val == "Null") return CommentKind::Null;
	else if(val == "Text") return CommentKind::Text;
	else if(val == "InlineCommand") return CommentKind::InlineCommand;
	else if(val == "HTMLStartTag") return CommentKind::HTMLStartTag;
	else if(val == "HTMLEndTag") return CommentKind::HTMLEndTag;
	else if(val == "Paragraph") return CommentKind::Paragraph;
	else if(val == "BlockCommand") return CommentKind::BlockCommand;
	else if(val == "ParamCommand") return CommentKind::ParamCommand;
	else if(val == "TParamCommand") return CommentKind::TParamCommand;
	else if(val == "VerbatimBlockCommand") return CommentKind::VerbatimBlockCommand;
	else if(val == "VerbatimBlockLine") return CommentKind::VerbatimBlockLine;
	else if(val == "VerbatimLine") return CommentKind::VerbatimLine;
	else if(val == "FullComment") return CommentKind::FullComment;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CommentInlineCommandRenderKind>(CommentInlineCommandRenderKind val) {
	switch(val) {
		case CommentInlineCommandRenderKind::Normal: return "Normal";
		case CommentInlineCommandRenderKind::Bold: return "Bold";
		case CommentInlineCommandRenderKind::Monospaced: return "Monospaced";
		case CommentInlineCommandRenderKind::Emphasized: return "Emphasized";
		default: throw InvalidEnumValueException<CommentInlineCommandRenderKind>(val);
	}
}

template<>
inline CommentInlineCommandRenderKind fromString<CommentInlineCommandRenderKind>(std::string val) {
	if(val == "Normal") return CommentInlineCommandRenderKind::Normal;
	else if(val == "Bold") return CommentInlineCommandRenderKind::Bold;
	else if(val == "Monospaced") return CommentInlineCommandRenderKind::Monospaced;
	else if(val == "Emphasized") return CommentInlineCommandRenderKind::Emphasized;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CommentParamPassDirection>(CommentParamPassDirection val) {
	switch(val) {
		case CommentParamPassDirection::In: return "In";
		case CommentParamPassDirection::Out: return "Out";
		case CommentParamPassDirection::InOut: return "InOut";
		default: throw InvalidEnumValueException<CommentParamPassDirection>(val);
	}
}

template<>
inline CommentParamPassDirection fromString<CommentParamPassDirection>(std::string val) {
	if(val == "In") return CommentParamPassDirection::In;
	else if(val == "Out") return CommentParamPassDirection::Out;
	else if(val == "InOut") return CommentParamPassDirection::InOut;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<NameRefFlags>(NameRefFlags val) {
	switch(val) {
		case NameRefFlags::WantQualifier: return "WantQualifier";
		case NameRefFlags::WantTemplateArgs: return "WantTemplateArgs";
		case NameRefFlags::WantSinglePiece: return "WantSinglePiece";
		default: throw InvalidEnumValueException<NameRefFlags>(val);
	}
}

template<>
inline NameRefFlags fromString<NameRefFlags>(std::string val) {
	if(val == "WantQualifier") return NameRefFlags::WantQualifier;
	else if(val == "WantTemplateArgs") return NameRefFlags::WantTemplateArgs;
	else if(val == "WantSinglePiece") return NameRefFlags::WantSinglePiece;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<TokenKind>(TokenKind val) {
	switch(val) {
		case TokenKind::Punctuation: return "Punctuation";
		case TokenKind::Keyword: return "Keyword";
		case TokenKind::Identifier: return "Identifier";
		case TokenKind::Literal: return "Literal";
		case TokenKind::Comment: return "Comment";
		default: throw InvalidEnumValueException<TokenKind>(val);
	}
}

template<>
inline TokenKind fromString<TokenKind>(std::string val) {
	if(val == "Punctuation") return TokenKind::Punctuation;
	else if(val == "Keyword") return TokenKind::Keyword;
	else if(val == "Identifier") return TokenKind::Identifier;
	else if(val == "Literal") return TokenKind::Literal;
	else if(val == "Comment") return TokenKind::Comment;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CompletionChunkKind>(CompletionChunkKind val) {
	switch(val) {
		case CompletionChunkKind::Optional: return "Optional";
		case CompletionChunkKind::TypedText: return "TypedText";
		case CompletionChunkKind::Text: return "Text";
		case CompletionChunkKind::Placeholder: return "Placeholder";
		case CompletionChunkKind::Informative: return "Informative";
		case CompletionChunkKind::CurrentParameter: return "CurrentParameter";
		case CompletionChunkKind::LeftParen: return "LeftParen";
		case CompletionChunkKind::RightParen: return "RightParen";
		case CompletionChunkKind::LeftBracket: return "LeftBracket";
		case CompletionChunkKind::RightBracket: return "RightBracket";
		case CompletionChunkKind::LeftBrace: return "LeftBrace";
		case CompletionChunkKind::RightBrace: return "RightBrace";
		case CompletionChunkKind::LeftAngle: return "LeftAngle";
		case CompletionChunkKind::RightAngle: return "RightAngle";
		case CompletionChunkKind::Comma: return "Comma";
		case CompletionChunkKind::ResultType: return "ResultType";
		case CompletionChunkKind::Colon: return "Colon";
		case CompletionChunkKind::SemiColon: return "SemiColon";
		case CompletionChunkKind::Equal: return "Equal";
		case CompletionChunkKind::HorizontalSpace: return "HorizontalSpace";
		case CompletionChunkKind::VerticalSpace: return "VerticalSpace";
		default: throw InvalidEnumValueException<CompletionChunkKind>(val);
	}
}

template<>
inline CompletionChunkKind fromString<CompletionChunkKind>(std::string val) {
	if(val == "Optional") return CompletionChunkKind::Optional;
	else if(val == "TypedText") return CompletionChunkKind::TypedText;
	else if(val == "Text") return CompletionChunkKind::Text;
	else if(val == "Placeholder") return CompletionChunkKind::Placeholder;
	else if(val == "Informative") return CompletionChunkKind::Informative;
	else if(val == "CurrentParameter") return CompletionChunkKind::CurrentParameter;
	else if(val == "LeftParen") return CompletionChunkKind::LeftParen;
	else if(val == "RightParen") return CompletionChunkKind::RightParen;
	else if(val == "LeftBracket") return CompletionChunkKind::LeftBracket;
	else if(val == "RightBracket") return CompletionChunkKind::RightBracket;
	else if(val == "LeftBrace") return CompletionChunkKind::LeftBrace;
	else if(val == "RightBrace") return CompletionChunkKind::RightBrace;
	else if(val == "LeftAngle") return CompletionChunkKind::LeftAngle;
	else if(val == "RightAngle") return CompletionChunkKind::RightAngle;
	else if(val == "Comma") return CompletionChunkKind::Comma;
	else if(val == "ResultType") return CompletionChunkKind::ResultType;
	else if(val == "Colon") return CompletionChunkKind::Colon;
	else if(val == "SemiColon") return CompletionChunkKind::SemiColon;
	else if(val == "Equal") return CompletionChunkKind::Equal;
	else if(val == "HorizontalSpace") return CompletionChunkKind::HorizontalSpace;
	else if(val == "VerticalSpace") return CompletionChunkKind::VerticalSpace;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CodeComplete_Flags>(CodeComplete_Flags val) {
	switch(val) {
		case CodeComplete_Flags::IncludeMacros: return "IncludeMacros";
		case CodeComplete_Flags::IncludeCodePatterns: return "IncludeCodePatterns";
		case CodeComplete_Flags::IncludeBriefComments: return "IncludeBriefComments";
		default: throw InvalidEnumValueException<CodeComplete_Flags>(val);
	}
}

template<>
inline CodeComplete_Flags fromString<CodeComplete_Flags>(std::string val) {
	if(val == "IncludeMacros") return CodeComplete_Flags::IncludeMacros;
	else if(val == "IncludeCodePatterns") return CodeComplete_Flags::IncludeCodePatterns;
	else if(val == "IncludeBriefComments") return CodeComplete_Flags::IncludeBriefComments;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<CompletionContext>(CompletionContext val) {
	switch(val) {
		case CompletionContext::Unexposed: return "Unexposed";
		case CompletionContext::AnyType: return "AnyType";
		case CompletionContext::AnyValue: return "AnyValue";
		case CompletionContext::ObjCObjectValue: return "ObjCObjectValue";
		case CompletionContext::ObjCSelectorValue: return "ObjCSelectorValue";
		case CompletionContext::CXXClassTypeValue: return "CXXClassTypeValue";
		case CompletionContext::DotMemberAccess: return "DotMemberAccess";
		case CompletionContext::ArrowMemberAccess: return "ArrowMemberAccess";
		case CompletionContext::ObjCPropertyAccess: return "ObjCPropertyAccess";
		case CompletionContext::EnumTag: return "EnumTag";
		case CompletionContext::UnionTag: return "UnionTag";
		case CompletionContext::StructTag: return "StructTag";
		case CompletionContext::ClassTag: return "ClassTag";
		case CompletionContext::Namespace: return "Namespace";
		case CompletionContext::NestedNameSpecifier: return "NestedNameSpecifier";
		case CompletionContext::ObjCInterface: return "ObjCInterface";
		case CompletionContext::ObjCProtocol: return "ObjCProtocol";
		case CompletionContext::ObjCCategory: return "ObjCCategory";
		case CompletionContext::ObjCInstanceMessage: return "ObjCInstanceMessage";
		case CompletionContext::ObjCClassMessage: return "ObjCClassMessage";
		case CompletionContext::ObjCSelectorName: return "ObjCSelectorName";
		case CompletionContext::MacroName: return "MacroName";
		case CompletionContext::NaturalLanguage: return "NaturalLanguage";
		case CompletionContext::Unknown: return "Unknown";
		default: throw InvalidEnumValueException<CompletionContext>(val);
	}
}

template<>
inline CompletionContext fromString<CompletionContext>(std::string val) {
	if(val == "Unexposed") return CompletionContext::Unexposed;
	else if(val == "AnyType") return CompletionContext::AnyType;
	else if(val == "AnyValue") return CompletionContext::AnyValue;
	else if(val == "ObjCObjectValue") return CompletionContext::ObjCObjectValue;
	else if(val == "ObjCSelectorValue") return CompletionContext::ObjCSelectorValue;
	else if(val == "CXXClassTypeValue") return CompletionContext::CXXClassTypeValue;
	else if(val == "DotMemberAccess") return CompletionContext::DotMemberAccess;
	else if(val == "ArrowMemberAccess") return CompletionContext::ArrowMemberAccess;
	else if(val == "ObjCPropertyAccess") return CompletionContext::ObjCPropertyAccess;
	else if(val == "EnumTag") return CompletionContext::EnumTag;
	else if(val == "UnionTag") return CompletionContext::UnionTag;
	else if(val == "StructTag") return CompletionContext::StructTag;
	else if(val == "ClassTag") return CompletionContext::ClassTag;
	else if(val == "Namespace") return CompletionContext::Namespace;
	else if(val == "NestedNameSpecifier") return CompletionContext::NestedNameSpecifier;
	else if(val == "ObjCInterface") return CompletionContext::ObjCInterface;
	else if(val == "ObjCProtocol") return CompletionContext::ObjCProtocol;
	else if(val == "ObjCCategory") return CompletionContext::ObjCCategory;
	else if(val == "ObjCInstanceMessage") return CompletionContext::ObjCInstanceMessage;
	else if(val == "ObjCClassMessage") return CompletionContext::ObjCClassMessage;
	else if(val == "ObjCSelectorName") return CompletionContext::ObjCSelectorName;
	else if(val == "MacroName") return CompletionContext::MacroName;
	else if(val == "NaturalLanguage") return CompletionContext::NaturalLanguage;
	else if(val == "Unknown") return CompletionContext::Unknown;
	else throw InvalidStringValueException(val);
}

template<>
inline std::string toString<VisitorResult>(VisitorResult val) {
	switch(val) {
		case VisitorResult::Break: return "Break";
		case VisitorResult::Continue: return "Continue";
		default: throw InvalidEnumValueException<VisitorResult>(val);
	}
}

template<>
inline VisitorResult fromString<VisitorResult>(std::string val) {
	if(val == "Break") return VisitorResult::Break;
	else if(val == "Continue") return VisitorResult::Continue;
	else throw InvalidStringValueException(val);
}

}