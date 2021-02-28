// SoftEther VPN Source Code - Developer Edition Master Branch
// Cedar Communication Module


// Win32Com.h
// Header of Win32Com.c

#ifndef	WIN32COM_H
#define	WIN32COM_H

#if	defined(__cplusplus)
extern "C"
{
#endif

	void ShowHtml(HWND hWnd, char *url, wchar_t *option);
	bool CreateLink(wchar_t *filename, wchar_t *target, wchar_t *workdir, wchar_t *args,
		wchar_t *comment, wchar_t *icon, UINT icon_index);
	wchar_t *FolderDlgW(HWND hWnd, wchar_t *title, wchar_t *default_dir);
	char *FolderDlgA(HWND hWnd, wchar_t *title, char *default_dir);

	bool InstallNdisProtocolDriver(wchar_t *inf_path, wchar_t *id, UINT lock_timeout);
	bool UninstallNdisProtocolDriver(wchar_t *id, UINT lock_timeout);

	bool Win32UPnPAddPort(UINT outside_port, UINT inside_port, bool udp, char *local_ip, wchar_t *description, bool remove_before_add);

	//////////////////////////////////////////////////////////////////////////
	//JumpList

	//Application ID for VPN Client Manager
	#define APPID_CM GC_UI_APPID_CM

	typedef void* JL_PCustomDestinationList;
	typedef void* JL_PObjectArray;
	typedef void* JL_PShellLink;
	typedef void* JL_PObjectCollection;
	typedef long JL_HRESULT;

	JL_HRESULT JL_CreateCustomDestinationList(JL_PCustomDestinationList* poc, wchar_t* appID);
	JL_HRESULT JL_ReleaseCustomDestinationList(JL_PCustomDestinationList poc);

	JL_HRESULT JL_BeginList(JL_PCustomDestinationList poc, JL_PObjectArray* oaRemoved);
	JL_HRESULT JL_CommitList(JL_PCustomDestinationList cdl);


	JL_HRESULT JL_CreateObjectCollection(JL_PObjectCollection* poc);
	JL_HRESULT JL_ReleaseObjectCollection(JL_PObjectCollection poc);
	JL_HRESULT JL_ObjectCollectionAddShellLink(JL_PObjectCollection poc, JL_PShellLink ppsl);

	JL_HRESULT JL_AddCategoryToList(JL_PCustomDestinationList pcdl, 
		JL_PObjectCollection poc, 
		wchar_t* categoryName,
		JL_PObjectArray poaRemoved);
	JL_HRESULT JL_DeleteJumpList(JL_PCustomDestinationList jpcdl,wchar_t* appID);


	JL_HRESULT JL_CreateShellLink(
		wchar_t* pszPath, 
		wchar_t* pszArguments, 
		wchar_t* pszTitle, 
		wchar_t* iconLocation,
		int iconIndex,
		wchar_t* description, JL_PShellLink *ppsl);
	JL_HRESULT JL_ReleaseShellLink(JL_PShellLink ppsl);


	//SetApplicationID for Windows 7
	JL_HRESULT JL_SetCurrentProcessExplicitAppUserModelID(wchar_t* appID);


	//JL_HRESULT JL_AddTasksToList(JL_PCustomDestinationList pcdl, JL_PObjectCollection poc);

	//////////////////////////////////////////////////////////////////////////
	//DrawImage
	// 

	#if	defined(__cplusplus)
	
typedef UCHAR ct_uchar;
typedef char ct_char;

#define ct_max(a,b) (((a) > (b)) ? (a): (b))
#define ct_min(a,b) (((a) < (b)) ? (a): (b))
#define ct_clamp(n,mi,ma) (ct_max(ct_min((n),(ma)),(mi)))
#define ct_clamp01(n) ct_clamp(n,0,1)

/**
* Union representing 32-bit color with alpha channel.
* CT_Color32, CT_AHSV32, CT_AYCbCr32 are also the same.
*
*/
typedef union CT_ARGB32
{
public:

	/** 32-bit integer intensity */
	UINT ARGB;

	/** RGB Color System */
	struct  
	{
		ct_uchar B;
		ct_uchar G;
		ct_uchar R;
		ct_uchar A;
	};

	/** HSV Color System */
	struct HSVA
	{
		ct_uchar V;
		ct_uchar S;
		ct_uchar H;
		ct_uchar A;
	}HSVA;

	/** YCbCr Color System */
	struct  YCbCrA
	{
		ct_uchar Y;
		ct_char Cb;
		ct_char Cr;
		ct_uchar A;
	}YCbCrA;


	/** Default constructor */
	CT_ARGB32(){}

	/** Constructor to initialize by specified color.
	* @param a Alpha channel
	* @param r Red, Hue, Cr
	* @param g Green, Saturation, Cb
	* @param b Blue, Value, Y
	*/
	CT_ARGB32(ct_uchar a,ct_uchar r,ct_uchar g,ct_uchar b)
	{
		A = a;
		R = r;
		G = g;
		B = b;
	}



}CT_ARGB32;


class CT_Size
{
public:
	int Width;
	int Height;

	CT_Size(int w, int h)
	{
		Width = w;
		Height = h;
	}
};

class CT_Rect
{
public:
	int X;
	int Y;
	int Width;
	int Height;

	CT_Rect()
	{	
		X = 0;
		Y = 0;
		Width = 0;
		Height = 0;
	}

	CT_Rect(int x, int y,int w, int h)
	{	
		X = x;
		Y = y;
		Width = w;
		Height = h;
	}

	int Right(){return X + Width;}
	int Bottom(){return Y + Height;}

	void Right(int r){ Width = r - X;}
	void Bottom(int b){ Height = b - Y;}

};



#endif //__cplusplus

typedef struct CT_RectF_c
{
	float X;
	float Y;
	float Width;
	float Height;
} CT_RectF_c;

void CT_DrawImage(UCHAR* dest, CT_RectF_c destRect, int destWidth, int destHeight,
				  UCHAR* src, CT_RectF_c srcRect, int srcWidth, int srcHeight);



#if	defined(__cplusplus)
}
#endif


//EXTERN_C const IID IID_IObjectCollection;
//EXTERN_C const IID IID_ICustomDestinationList;

#if defined(__cplusplus)


#ifndef	__IObjectArray_INTERFACE_DEFINED__
#define	__IObjectArray_INTERFACE_DEFINED__

MIDL_INTERFACE("92CA9DCD-5622-4bba-A805-5E9F541BD8C9")
IObjectArray : public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE GetCount( 
		/* [out] */ __RPC__out UINT *pcObjects) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetAt( 
		/* [in] */ UINT uiIndex,
		/* [in] */ __RPC__in REFIID riid,
		/* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;

};

MIDL_INTERFACE("5632b1a4-e38a-400a-928a-d4cd63230295")
IObjectCollection : public IObjectArray
{
public:
	virtual HRESULT STDMETHODCALLTYPE AddObject( 
		/* [in] */ __RPC__in_opt IUnknown *punk) = 0;

	virtual HRESULT STDMETHODCALLTYPE AddFromArray( 
		/* [in] */ __RPC__in_opt IObjectArray *poaSource) = 0;

	virtual HRESULT STDMETHODCALLTYPE RemoveObjectAt( 
		/* [in] */ UINT uiIndex) = 0;

	virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;

};

#endif	// __IObjectArray_INTERFACE_DEFINED__

#ifndef	__ICustomDestinationList_INTERFACE_DEFINED__
#define	__ICustomDestinationList_INTERFACE_DEFINED__

typedef /* [v1_enum] */ 
enum KNOWNDESTCATEGORY
{	
	KDC_FREQUENT	= 1,
	KDC_RECENT	= ( KDC_FREQUENT + 1 ) 
} 	KNOWNDESTCATEGORY;

MIDL_INTERFACE("6332debf-87b5-4670-90c0-5e57b408a49e")
ICustomDestinationList : public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE SetAppID( 
		/* [string][in] */ __RPC__in_string LPCWSTR pszAppID) = 0;

	virtual HRESULT STDMETHODCALLTYPE BeginList( 
		/* [out] */ __RPC__out UINT *pcMinSlots,
		/* [in] */ __RPC__in REFIID riid,
		/* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;

	virtual HRESULT STDMETHODCALLTYPE AppendCategory( 
		/* [string][in] */ __RPC__in_string LPCWSTR pszCategory,
		/* [in] */ __RPC__in_opt IObjectArray *poa) = 0;

	virtual HRESULT STDMETHODCALLTYPE AppendKnownCategory( 
		/* [in] */ KNOWNDESTCATEGORY category) = 0;

	virtual HRESULT STDMETHODCALLTYPE AddUserTasks( 
		/* [in] */ __RPC__in_opt IObjectArray *poa) = 0;

	virtual HRESULT STDMETHODCALLTYPE CommitList( void) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetRemovedDestinations( 
		/* [in] */ __RPC__in REFIID riid,
		/* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;

	virtual HRESULT STDMETHODCALLTYPE DeleteList( 
		/* [string][unique][in] */ __RPC__in_opt_string LPCWSTR pszAppID) = 0;

	virtual HRESULT STDMETHODCALLTYPE AbortList( void) = 0;

};


#endif	// __ICustomDestinationList_INTERFACE_DEFINED__


#endif //defined(__cplusplus)



#endif	// WIN32COM_H
