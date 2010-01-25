#pragma once

#include <map>
#include <list>
using namespace std;

class CPhotoSetInfo
{
	public:
		CPhotoSetInfo  (CString _sName, CString _sDescription = "", CString _sID = "", bool _bNew = false);
		~CPhotoSetInfo (void);

		CPhotoSetInfo* Clone (void);

		typedef list <CPhotoSetInfo*>			PhotoSetInfo_lst_t;
		typedef map  <CString, CPhotoSetInfo*>	PhotoSetInfoByName_map_t;

		CString		s_Name;
		CString		s_Description;
		CString		s_ID;
		bool		b_New;
};
