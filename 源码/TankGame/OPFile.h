#pragma once
class OPFile
{
public:
	OPFile();
	~OPFile();
	void ReadMap(char* mName);
	/************************************
	* Method:    SaveMap
	* FullName:  SaveMap
	* Access:    public
	* Returns:   void
	* Qualifier:
	************************************/
	void SaveMap();
	/************************************
	* Method:    ReadRecord
	* FullName:  ReadRecord
	* Access:    public
	* Returns:   void
	* Qualifier:
	* Parameter: char * mName
	************************************/
	void ReadRecord(char* mName);
	/************************************
	* Method:    SaveRecord
	* FullName:  SaveRecord
	* Access:    public
	* Returns:   void
	* Qualifier:
	************************************/
	void SaveRecord();
	/************************************
	* Method:    SaveName
	* FullName:  SaveName
	* Access:    public
	* Returns:   void
	* Qualifier:
	* Parameter: char * pst
	* Parameter: int n
	************************************/
	void SaveName(char* pst, int n);
	/************************************
	* Method:    SaveName
	* FullName:  SaveName
	* Access:    public
	* Returns:   void
	* Qualifier:
	************************************/
	void SaveName();
	/************************************
	* Method:    ReadName
	* FullName:  ReadName
	* Access:    public
	* Returns:   void
	* Qualifier:
	************************************/
	void ReadName();
	/************************************
	* Method:    ClearFile
	* FullName:  ClearFile
	* Access:    public
	* Returns:   void
	* Qualifier:
	* Parameter: char * name
	* Parameter: int mark
	************************************/
	void ClearFile(char* name, int mark);
	/************************************
	* Method:    DeleteName
	* FullName:  DeleteName
	* Access:    public
	* Returns:   void
	* Qualifier:
	* Parameter: int mark
	* Parameter: int index
	************************************/
	void DeleteName(int mark, int index);

private:

};


