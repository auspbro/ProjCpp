

#define WANGYU_API _declspec(dllimport)


//////////////////////////////////////////////////////////////////////////
extern "C"
{
	WANGYU_API void _stdcall  GetCorollaVersion(char* Version);	
	WANGYU_API int  _stdcall  GetOneInforByWMI(char* ClassName,char* Member,int index,char* Reslut);
};
