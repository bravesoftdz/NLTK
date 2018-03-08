//---------------------------------------------------------------------------

#ifndef wAcceptChangesH
#define wAcceptChangesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TAcceptChangesDlg : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TStringGrid *gridChanges;
	TPanel *pnlCmd;
	TButton *btnAccept;
	TButton *btnCancel;
private:	// D�clarations utilisateur
public:		// D�clarations utilisateur

    // m�thodes publiques :
    //---------------------
    bool __fastcall execute();

    // constructeurs & destructeur :
    //------------------------------
			__fastcall TAcceptChangesDlg(TComponent* Owner);
    virtual __fastcall ~TAcceptChangesDlg();
};
//---------------------------------------------------------------------------
extern PACKAGE TAcceptChangesDlg *AcceptChangesDlg;
//---------------------------------------------------------------------------
#endif
