#pragma once

#include <map>
#include <set>
using namespace std;

class CImageDetails
{
	public:
		CImageDetails (void);
		~CImageDetails (void);

		typedef	set <CString>				PhotoSetName_set_t;
		typedef map <int, CImageDetails*>	ImageDetailsByItemIndex_map_t;

		CString				s_Title;
		CString				s_Description;
		CString				s_Tags;
		bool				b_OnlyMe;
		bool				b_Family;
		bool				b_Friends;
		bool				b_Anyone;
		int					i_SafetyLevel;
		int					i_Hidden;
		int					i_ContentType;
		PhotoSetName_set_t	set_SelectedSets;
		CString				s_FileName;
		CString				s_FileSize;
};
