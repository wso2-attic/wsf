#pragma once

#include <map>
using namespace std;

class CImageDetails
{
	public:
		CImageDetails (void);
		~CImageDetails (void);

		typedef map <int, CImageDetails*>	ImageDetailsByItemIndex_map_t;

		CString		s_FileName;
		CString		s_FileSize;
		CString		s_Title;
		CString		s_Description;
		CString		s_Tags;
		char		c_OnlyMe;
		char		c_Family;
		char		c_Friends;
		char		c_Anyone;
		char		c_SafetyLevel;
		char		c_Hidden;
		char		c_ContentType;
};
