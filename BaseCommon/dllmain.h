// dllmain.h: 模块类的声明。

class CBaseCommonModule : public ATL::CAtlDllModuleT< CBaseCommonModule >
{
public :
	DECLARE_LIBID(LIBID_BaseCommonLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_BASECOMMON, "{E30CA431-1B3E-49EA-9E77-3BD9AB969DF2}")
};

extern class CBaseCommonModule _AtlModule;
