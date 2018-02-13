//---------------------------------------------------------------------------

#ifndef wMainH
#define wMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TMainDlg : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TButton *brnPlayerDebug;
	TButton *btnRosters;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall brnPlayerDebugClick(TObject *Sender);
	void __fastcall btnRostersClick(TObject *Sender);
private:	// D�clarations utilisateur


    // m�thodes internes :
    //--------------------
    void __fastcall zero();
    void __fastcall init();
    void __fastcall deinit();
    void __fastcall formInit();
    void __fastcall formDeinit();

    // variables internes :
    //---------------------
    TRosterEditorDlg* _rosterEditor;


public:		// D�clarations utilisateur

    // constructeurs & destructeur :
    //------------------------------
			__fastcall TMainDlg(TComponent* Owner);
    virtual __fastcall ~TMainDlg();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainDlg *MainDlg;
//---------------------------------------------------------------------------
#endif
