// Header file for the MFCMAPI application registry functions

#pragma once

namespace registry
{
#define RKEY_ROOT L"SOFTWARE\\Microsoft\\MFCMAPI" // STRING_OK

	enum __REGKEYTYPES
	{
		regDWORD,
		regSTRING
	};

	enum __REGOPTIONTYPE
	{
		regoptCheck,
		regoptString,
		regoptStringHex,
		regoptStringDec
	};

	struct __RegKeys
	{
		std::wstring szKeyName;
		ULONG ulRegKeyType;
		ULONG ulRegOptType;
		DWORD ulDefDWORD;
		DWORD ulCurDWORD;
		std::wstring szDefSTRING;
		std::wstring szCurSTRING;
		bool bRefresh;
		UINT uiOptionsPrompt;
	};

	// Registry key Names
	enum REGKEYNAMES
	{
		regkeyDEBUG_TAG,
		regkeyDEBUG_TO_FILE,
		regkeyDEBUG_FILE_NAME,
		regkeyPARSED_NAMED_PROPS,
		regkeyGETPROPNAMES_ON_ALL_PROPS,
		regkeyTHROTTLE_LEVEL,
		regkeyHIER_EXPAND_NOTIFS,
		regkeyHIER_ROOT_NOTIFS,
		regkeyDO_SMART_VIEW,
		regkeyONLY_ADDITIONAL_PROPERTIES,
		regkeyUSE_ROW_DATA_FOR_SINGLEPROPLIST,
		regkeyUSE_GETPROPLIST,
		regkeyPREFER_UNICODE_PROPS,
		regkeyCACHE_NAME_DPROPS,
		regkeyALLOW_DUPE_COLUMNS,
		regkeyDO_COLUMN_NAMES,
		regkeyEDIT_COLUMNS_ON_LOAD,
		regkeyMDB_ONLINE,
		regKeyMAPI_NO_CACHE,
		regkeyALLOW_PERSIST_CACHE,
		regkeyUSE_IMAPIPROGRESS,
		regkeyUSE_MESSAGERAW,
		regkeySUPPRESS_NOT_FOUND,
		regkeyHEAPENABLETERMINATIONONCORRUPTION,
		regkeyLOADADDINS,
		regkeyFORCEOUTLOOKMAPI,
		regkeyFORCESYSTEMMAPI,
		regkeyHEX_DIALOG_DIAG,
		regkeyDISPLAY_ABOUT_DIALOG,
		regkeyPROP_COLUMN_ORDER,
		NUMRegKeys
	};

#define NumRegOptionKeys (registry::NUMRegKeys - 2)

	extern __RegKeys RegKeys[NUMRegKeys];

	void SetDefaults();
	void WriteToRegistry();
	void ReadFromRegistry();

	_Check_return_ HKEY CreateRootKey();

	DWORD ReadDWORDFromRegistry(_In_ HKEY hKey, _In_ const std::wstring& szValue, _In_ DWORD dwDefaultVal = 0);
	std::wstring ReadStringFromRegistry(
		_In_ HKEY hKey,
		_In_ const std::wstring& szValue,
		_In_ const std::wstring& szDefault = strings::emptystring);

	void WriteStringToRegistry(_In_ HKEY hKey, _In_ const std::wstring& szValueName, _In_ const std::wstring& szValue);

	class boolReg
	{
		DWORD& _val;

	public:
		boolReg(DWORD& val) : _val(val) {}
		boolReg(__RegKeys& val) : _val(val.ulCurDWORD) {}
		operator bool() const { return _val != 0; }

		bool operator=(DWORD val)
		{
			_val = val;
			return _val;
		}
	};

	// Registry setting accessors
	//regkeyDEBUG_TAG,
	static boolReg debugToFile = RegKeys[regkeyDEBUG_TO_FILE];
	//regkeyDEBUG_FILE_NAME,
	static boolReg parseNamedProps = RegKeys[regkeyPARSED_NAMED_PROPS];
	static boolReg getPropsNamesOnAllProps = RegKeys[regkeyGETPROPNAMES_ON_ALL_PROPS];
	//regkeyTHROTTLE_LEVEL,
	static boolReg hierExpandNotifications = RegKeys[regkeyHIER_EXPAND_NOTIFS];
	static boolReg hierRootNotifs = RegKeys[regkeyHIER_ROOT_NOTIFS];
	static boolReg doSmartView = RegKeys[regkeyDO_SMART_VIEW];
	static boolReg onlyAdditionalProperties = RegKeys[regkeyONLY_ADDITIONAL_PROPERTIES];
	static boolReg useRowDataForSinglePropList = RegKeys[regkeyUSE_ROW_DATA_FOR_SINGLEPROPLIST];
	static boolReg useGetPropList = RegKeys[regkeyUSE_GETPROPLIST];
	static boolReg preferUnicodeProps = RegKeys[regkeyPREFER_UNICODE_PROPS];
	static boolReg cacheNamedProps = RegKeys[regkeyCACHE_NAME_DPROPS];
	static boolReg allowDupeColumns = RegKeys[regkeyALLOW_DUPE_COLUMNS];
	static boolReg doColumnNames = RegKeys[regkeyDO_COLUMN_NAMES];
	static boolReg editColumnsOnLoad = RegKeys[regkeyEDIT_COLUMNS_ON_LOAD];
	static boolReg forceMDBOnline = RegKeys[regkeyMDB_ONLINE];
	static boolReg forceMapiNoCache = RegKeys[regKeyMAPI_NO_CACHE];
	static boolReg allowPersistCache = RegKeys[regkeyALLOW_PERSIST_CACHE];
	static boolReg useIMAPIProgress = RegKeys[regkeyUSE_IMAPIPROGRESS];
	static boolReg useMessageRaw = RegKeys[regkeyUSE_MESSAGERAW];
	static boolReg suppressNotFound = RegKeys[regkeySUPPRESS_NOT_FOUND];
	static boolReg heapEnableTerminationOnCorruption = RegKeys[regkeyHEAPENABLETERMINATIONONCORRUPTION];
	static boolReg loadAddIns = RegKeys[regkeyLOADADDINS];
	static boolReg forceOutlookMAPI = RegKeys[regkeyFORCEOUTLOOKMAPI];
	static boolReg forceSystemMAPI = RegKeys[regkeyFORCESYSTEMMAPI];
	static boolReg hexDialogDiag = RegKeys[regkeyHEX_DIALOG_DIAG];
	static boolReg displayAboutDialog = RegKeys[regkeyDISPLAY_ABOUT_DIALOG];
	//regkeyPROP_COLUMN_ORDER,
} // namespace registry