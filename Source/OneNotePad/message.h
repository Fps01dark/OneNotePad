#pragma once

enum Message
{
	// File
	NewFile,
	OpenFile,
	OpenExplorer,
	OpenCmd,
	OpenDirectoryWorkspace,
	OpenDirectoryAsWorkspace,
	OpenInDefaultViewer,
	ReloadFile,
	SaveFile,
	SaveAsFile,
	SaveAllFile,
	SaveAsClipboard,
	CloseFile,
	CloseAllFile,
	CloseAllButCurrentFile,
	CloseLeftFile,
	CloseRightFile,
	CloseAllUnchangedFile,
	DeleteFile,
	LoadSession,
	SaveSession,
	Print,
	ClearRecentRecord,
	ExitSoftware,

	// Eidt
	Undo,
	Redo,
	Copy,
	Paste,
	Delete,
	SelectAll,
	BeginEndSelect,
	BeginEndSelectInColumnMode,
	InsertShortTime,
	InsertLongTime,
	InsertCustomTime,
	CopyAllNames,
	CopyAllPaths,
	IncreaseLineIndent,
	DecreaseLineIndent,
	Uppercase,
	Lowercase,
	ProperCase,
	ProperCaseBlend,
	SentenceCase,
	SentenceCaseBlend,
	InsertCase,
	RandomCase,
	DuplicateCurrentLine,
	RemoveDuplicateLine,
	RemoveConsecutiveDuplicateLines,
	SplitLines,
	JoinLines,
	MoveUpCurrentLine,
	MoveDownCurrentLine,
	RemoveEmptyLines,
	RemoveEmptyLinesBlank,
	InsertBlankLineAboveCurrent,
	InsertBlankLineBelowCurrent,
	ReverseLineOrder,
	RandomizeLineOrder,
	EolConversion,
	TrimTrailingSpace,

	// Help
	AboutOneNotePad,
	DebugInfo,

	// MenuBar
	AddRecentFile,
	UpdateMenuBar,

	// Directory
	CopyPath,
	CopyName,

	// QTabWidget
	TextChanged,
	CopyDirectory,
	ChangeZoom,

	// StatusBar
	UpdateStatusBar,
	UpdateLanguage,
	UpdateDocumentSize,
	UpdateSelectionInfo,
	UpdateEol,
	UpdateEncoding,
	UpdateOverType
};