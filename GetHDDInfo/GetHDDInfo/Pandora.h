#define PANDORA_API _declspec(dllimport)

extern "C"
{
		//Pandora.cpp
		//得到Pandora Dll的版本
		PANDORA_API void _stdcall GetPandoraVersion(char* PandoraVersion);	


		//T001_CreateTestReport.cpp
		//创建测试报告
		PANDORA_API bool _stdcall CreateTestReport(char* TestItemName,
			char* ReportPath ,//log file path
			char* ReportFileName, //log file name
			bool  TestReuslt, // Test result, pass is ture, failed is false
			BYTE  Flag = 2,         //0-no log file, 1- pass create, 2-failed create, 3 -pass\failed create, other - return FALSE
			bool  CreateOnefolderIfNoExist = true);

		//创建测试报告
		PANDORA_API bool _stdcall CreateTestReportEx(char* TestItemName,
			char* ReportPath ,//log file path
			bool  TestReuslt,
			BYTE  Flag = 2);         //0-no log file, 1- pass create, 2-failed create, 3 -pass\failed create, other - return FALSE					  


		PANDORA_API void _stdcall ShowAbout(char* ProgramName,char* ProgramVersion, char* CreateDate); // for console application
		PANDORA_API void _stdcall ShowAboutDlg(char* ProgramName,char* ProgramVersion, char* CreateDate); // for MFC application
};
