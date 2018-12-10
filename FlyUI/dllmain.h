// dllmain.h: 模块类的声明。

class CFlyUIModule : public ATL::CAtlDllModuleT< CFlyUIModule >
{
public :
	DECLARE_LIBID(LIBID_FlyUILib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FLYUI, "{D9E9CEFD-ABA3-4BC8-B6BC-13C690937283}")
};

extern class CFlyUIModule _AtlModule;
