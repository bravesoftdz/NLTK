//---------------------------------------------------------------------------

#pragma hdrstop

//===========================================================================
#include <vcl.h>
#include "NLTK_common.h"
//---------------------------------------------------------------------------
#include "nlPlayer.h"
//---------------------------------------------------------------------------
//===========================================================================

#pragma package(smart_init)

//===========================================================================
// initialisation des variables statiques :
//---------------------------------------------------------------------------
DWORD CNLPlayer::_instanceCount = 0;
TStrings* CNLPlayer::_fieldNames = NULL;
//===========================================================================


//===========================================================================
// CONSTANTES : liste des noms de champs de la table PLAYERS
//---------------------------------------------------------------------------
#define FIELD_ID	      	AnsiString( "PLAYERID" )
#define FIELD_NAME        	AnsiString( "NAME" )
#define FIELD_FNAME       	AnsiString( "FNAME" )
#define FIELD_POSITION1    	AnsiString( "POSITION" )
#define FIELD_POSITION2     AnsiString( "POSITION2" )
#define FIELD_NUMBER        AnsiString( "NUMBER" )
#define FIELD_HEIGHT        AnsiString( "HEIGHT" )
#define FIELD_WEIGHT        AnsiString( "WEIGHT" )
#define FIELD_TEAM          AnsiString( "TEAM" )
#define FIELD_ROSTERPOS     AnsiString( "ROSTERPOS" )
#define FIELD_INSEASON      AnsiString( "INSEASON" )
#define FIELD_OVERALLRTG    AnsiString( "OVERALLRTG" )
#define FIELD_YEARSEXP      AnsiString( "YEARSEXP" )
#define FIELD_INJURYID      AnsiString( "INJURYID" )
#define FIELD_ISPLAYABLE    AnsiString( "ISPLAYABLE" )

#define FIELD_SGM        	AnsiString( "SGAMES" )
#define FIELD_SGMS		    AnsiString( "SGAMESTART" )
#define FIELD_SFGA  	 	AnsiString( "SFGATTEMPT" )
#define FIELD_SFGM	       	AnsiString( "SFGMADE" )
#define FIELD_S3PA			AnsiString( "STHREEPTAT" )
#define FIELD_S3PM			AnsiString( "STHREEPTMA" )
#define FIELD_SFTA		    AnsiString( "SFTATTEMPT" )
#define FIELD_SFTM	        AnsiString( "SFTMADE" )
#define FIELD_SBLK		    AnsiString( "SBLOCKS" )
#define FIELD_SORB		    AnsiString( "SOFFREB" )
#define FIELD_SAST	        AnsiString( "SASSISTS" )
#define FIELD_SFLS	        AnsiString( "SPERFOUL" )
#define FIELD_SSTL	        AnsiString( "SSTEALS" )
#define FIELD_SDRB	        AnsiString( "SDEFREB" )
#define FIELD_STO		    AnsiString( "STURNOVERS" )
#define FIELD_SMIN	        AnsiString( "SMINUTES" )
#define FIELD_SEJT	        AnsiString( "SEJECTS" )
//===========================================================================
// CONSTANTES : liste des positions
//---------------------------------------------------------------------------
#define POS_PG           4
#define POS_SG           3
#define POS_SF           2
#define POS_PF           1
#define POS_C            0
#define POS_NONE	  	-1
#define POS_UNDEF       -2
//---------------------------------------------------------------------------
#define POS_PG_TXT          AnsiString( "PG" )
#define POS_SG_TXT          AnsiString( "SG" )
#define POS_SF_TXT          AnsiString( "SF" )
#define POS_PF_TXT          AnsiString( "PF" )
#define POS_C_TXT           AnsiString( "C"  )
#define POS_NONE_TXT        AnsiString( "-"  )
//===========================================================================
// CONSTANTES : liste des �quipes
//---------------------------------------------------------------------------
#define TEAM_UNDEF          ((WORD)-1)
//===========================================================================
// CONSTANTES : liste des ann�es d'exp
//---------------------------------------------------------------------------
#define YEARSEXP_UNDEF          ((WORD)-1)
//===========================================================================
// CONSTANTES : liste des roster position
//---------------------------------------------------------------------------
#define ROSTERPOS_STARTER_C 	0
#define ROSTERPOS_STARTER_PF    1
#define ROSTERPOS_STARTER_SF    2
#define ROSTERPOS_STARTER_SG    3
#define ROSTERPOS_STARTER_PG    4
#define ROSTERPOS_BENCH_1       5
#define ROSTERPOS_BENCH_2       6
#define ROSTERPOS_BENCH_3       7
#define ROSTERPOS_BENCH_4       8
#define ROSTERPOS_BENCH_5       9
#define ROSTERPOS_BENCH_6       10
#define ROSTERPOS_BENCH_7       11
#define ROSTERPOS_INACTIVE_1    12
#define ROSTERPOS_INACTIVE_2    13
#define ROSTERPOS_INACTIVE_3    14
#define ROSTERPOS_UNDEF		    ((WORD)-1)
//---------------------------------------------------------------------------
#define ROSTERPOS_MIN           ROSTERPOS_STARTER_C
#define ROSTERPOS_MAX           ROSTERPOS_INACTIVE_3
//---------------------------------------------------------------------------
#define ROSTERPOS_STARTER_C_TXT 	AnsiString( "C" )
#define ROSTERPOS_STARTER_PF_TXT    AnsiString( "PF" )
#define ROSTERPOS_STARTER_SF_TXT    AnsiString( "SF" )
#define ROSTERPOS_STARTER_SG_TXT    AnsiString( "SG" )
#define ROSTERPOS_STARTER_PG_TXT    AnsiString( "PG" )
#define ROSTERPOS_BENCH_1_TXT       AnsiString( "-" )
#define ROSTERPOS_BENCH_2_TXT       AnsiString( "-" )
#define ROSTERPOS_BENCH_3_TXT       AnsiString( "-" )
#define ROSTERPOS_BENCH_4_TXT       AnsiString( "-" )
#define ROSTERPOS_BENCH_5_TXT       AnsiString( "-" )
#define ROSTERPOS_BENCH_6_TXT       AnsiString( "-" )
#define ROSTERPOS_BENCH_7_TXT       AnsiString( "-" )
#define ROSTERPOS_INACTIVE_1_TXT    AnsiString( "IL" )
#define ROSTERPOS_INACTIVE_2_TXT    AnsiString( "IL" )
#define ROSTERPOS_INACTIVE_3_TXT    AnsiString( "IL" )
//===========================================================================



//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================
//---------------------------------------------------------------------------
__fastcall CNLPlayer::CNLPlayer()
{
    this->zero();
    this->init();

    this->_instanceCount++;
}
//---------------------------------------------------------------------------
__fastcall CNLPlayer::CNLPlayer( CDBTable* t )
{
	this->zero();

    this->init();

    this->_instanceCount++;

    this->loadFromTable( t );
}
//---------------------------------------------------------------------------
__fastcall CNLPlayer::~CNLPlayer()
{
    this->_instanceCount--;
    this->deinit();
    this->zero();
}
//---------------------------------------------------------------------------
bool __fastcall CNLPlayer::loadFromTable( CDBTable* t )
{
    bool ok = false;

    if ( this->_record && t )
    {
	    ok = this->_record->readFromTable( t );
    }

    return ok;
}
//---------------------------------------------------------------------------
void __fastcall CNLPlayer::loadDifs( TStrings* difs )
{
    if ( this->_record ) this->_record->loadDifs( difs );
}
//---------------------------------------------------------------------------
bool __fastcall CNLPlayer::saveToTable( CDBTable* t )
{
    bool ok = false;

    if ( this->_record && t )
    {
        if ( this->_record->writeToTable( t ) )
        {
            ok = t->post();
        }

    }

    return ok;
}
//---------------------------------------------------------------------------
void __fastcall CNLPlayer::zero()
{
    this->_record = NULL;
}
//---------------------------------------------------------------------------
void __fastcall CNLPlayer::init()
{
    if ( this->_instanceCount == 0 ) this->createFieldNames();

    this->_instanceCount++;

    this->_record = new CDBRecord();
    this->_record->createFields( this->_fieldNames );
}
//---------------------------------------------------------------------------
void __fastcall CNLPlayer::deinit()
{
    if ( this->_record )
    {
        this->_record->deleteFields( this->_fieldNames );
        delete this->_record;
        this->_record = NULL;
    }

    this->_instanceCount--;

    if ( this->_instanceCount == 0 ) this->deleteFieldNames();
}
//---------------------------------------------------------------------------
void __fastcall CNLPlayer::createFieldNames()
{
    if ( !CNLPlayer::_fieldNames )
    {
        CNLPlayer::_fieldNames = new TStringList();

        CNLPlayer::_fieldNames->Add( FIELD_ID );
        CNLPlayer::_fieldNames->Add( FIELD_NAME );
        CNLPlayer::_fieldNames->Add( FIELD_FNAME );
        CNLPlayer::_fieldNames->Add( FIELD_HEIGHT );
        CNLPlayer::_fieldNames->Add( FIELD_WEIGHT );
        CNLPlayer::_fieldNames->Add( FIELD_POSITION1 );
        CNLPlayer::_fieldNames->Add( FIELD_POSITION2 );
        CNLPlayer::_fieldNames->Add( FIELD_NUMBER );
        CNLPlayer::_fieldNames->Add( FIELD_TEAM );
        CNLPlayer::_fieldNames->Add( FIELD_ROSTERPOS );
        CNLPlayer::_fieldNames->Add( FIELD_INSEASON );
        CNLPlayer::_fieldNames->Add( FIELD_OVERALLRTG );
        CNLPlayer::_fieldNames->Add( FIELD_YEARSEXP );
        CNLPlayer::_fieldNames->Add( FIELD_INJURYID );
        CNLPlayer::_fieldNames->Add( FIELD_ISPLAYABLE );

        CNLPlayer::_fieldNames->Add( FIELD_SGM );
        CNLPlayer::_fieldNames->Add( FIELD_SGMS );
        CNLPlayer::_fieldNames->Add( FIELD_SFGA );
        CNLPlayer::_fieldNames->Add( FIELD_SFGM );
        CNLPlayer::_fieldNames->Add( FIELD_S3PA );
        CNLPlayer::_fieldNames->Add( FIELD_S3PM );
        CNLPlayer::_fieldNames->Add( FIELD_SFTA );
        CNLPlayer::_fieldNames->Add( FIELD_SFTM );
        CNLPlayer::_fieldNames->Add( FIELD_SBLK );
        CNLPlayer::_fieldNames->Add( FIELD_SORB );
	    CNLPlayer::_fieldNames->Add( FIELD_SAST );
        CNLPlayer::_fieldNames->Add( FIELD_SFLS );
        CNLPlayer::_fieldNames->Add( FIELD_SSTL );
        CNLPlayer::_fieldNames->Add( FIELD_SDRB );
        CNLPlayer::_fieldNames->Add( FIELD_STO );
        CNLPlayer::_fieldNames->Add( FIELD_SMIN );
        CNLPlayer::_fieldNames->Add( FIELD_SEJT );
    }
}
//---------------------------------------------------------------------------
void __fastcall CNLPlayer::deleteFieldNames()
{
    if ( CNLPlayer::_fieldNames )
    {
        CNLPlayer::_fieldNames->Clear();
        delete CNLPlayer::_fieldNames;
        CNLPlayer::_fieldNames = NULL;
    }
}
//---------------------------------------------------------------------------
bool __fastcall CNLPlayer::getDif()
{
    if ( this->_record )
    {
        return this->_record->dif;
    }

    return false;
}
//---------------------------------------------------------------------------
int __fastcall CNLPlayer::getRecordIndex()
{
    if ( this->_record )
    {
        return this->_record->recordIndex;
    }
    return -1;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getID()
{
    WORD ID = 0;

    if ( this->_record )
    {
        AnsiString ID_asString = this->_record->ram[ FIELD_ID ];
        ID = ID_asString.ToIntDef( 0 );
    }
    return ID;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CNLPlayer::getName()
{
    AnsiString NAME = TXT_NULL;
    if ( this->_record )
    {
        NAME = this->_record->ram[ FIELD_NAME ];
    }
    return NAME;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CNLPlayer::getFName()
{
    AnsiString FNAME = TXT_NULL;
    if ( this->_record )
    {
        FNAME = this->_record->ram[ FIELD_FNAME ];
    }
    return FNAME;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CNLPlayer::getNumber()
{
    AnsiString NUMBER = TXT_NULL;
    if ( this->_record )
    {
        int NUMBER_asInt = this->_record->ram[ FIELD_NUMBER ].ToIntDef(-2);
        if ( NUMBER_asInt >= 0 ) NUMBER = IntToStr( NUMBER_asInt );
        else if ( NUMBER_asInt == -1 ) NUMBER = AnsiString( "00" );
    }
    return NUMBER;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getWeight()
{
    WORD WEIGHT_kg = 0;

    if ( this->_record )
    {
        WORD WEIGHT_lb = this->_record->ram[ FIELD_WEIGHT ].ToIntDef( 0 );
        double lb = (double)WEIGHT_lb;
        double kg = lb / 2.2046;

        WEIGHT_kg = (int)(kg+0.5);
    }

    return WEIGHT_kg;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getHeight()
{
    WORD HEIGHT_cm = 0;

    if ( this->_record )
    {
        WORD HEIGHT_inch = this->_record->ram[ FIELD_HEIGHT ].ToIntDef( 0 );
        double inch = (double)HEIGHT_inch;
        double cm = inch / 0.39370;
        HEIGHT_cm = (int)(cm+0.5);
    }

    return HEIGHT_cm;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CNLPlayer::getPosition1()
{
    AnsiString POSITION1 = TXT_NULL;

    if ( this->_record )
    {
        int POSITION1_asInt = this->_record->ram[ FIELD_POSITION1 ].ToIntDef(POS_UNDEF);
        switch ( POSITION1_asInt )
        {
	        case POS_PG		: POSITION1 = POS_PG_TXT; break;
            case POS_SG		: POSITION1 = POS_SG_TXT; break;
            case POS_SF		: POSITION1 = POS_SF_TXT; break;
            case POS_PF		: POSITION1 = POS_PF_TXT; break;
            case POS_C		: POSITION1 = POS_C_TXT; break;
            case POS_NONE	: POSITION1 = POS_NONE_TXT; break;
        }
    }

    return POSITION1;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CNLPlayer::getPosition2()
{
   AnsiString POSITION2 = TXT_NULL;

    if ( this->_record )
    {
        int POSITION2_asInt = this->_record->ram[ FIELD_POSITION2 ].ToIntDef(POS_UNDEF);
        switch ( POSITION2_asInt )
        {
	        case POS_PG		: POSITION2 = POS_PG_TXT; break;
            case POS_SG		: POSITION2 = POS_SG_TXT; break;
            case POS_SF		: POSITION2 = POS_SF_TXT; break;
            case POS_PF		: POSITION2 = POS_PF_TXT; break;
            case POS_C		: POSITION2 = POS_C_TXT; break;
            case POS_NONE	: POSITION2 = POS_NONE_TXT; break;
        }
    }

    return POSITION2;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getTeam()
{
    WORD TEAM = TEAM_UNDEF;

    if ( this->_record )
    {
        TEAM = this->_record->ram[ FIELD_TEAM ].ToIntDef( TEAM_UNDEF );
    }

    return TEAM;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getRosterPos()
{

    WORD ROSTERPOS = ROSTERPOS_UNDEF;

    if ( this->_record )
    {

        int rosterPos = this->_record->ram[ FIELD_ROSTERPOS ].ToIntDef(ROSTERPOS_UNDEF);
        if ( rosterPos >= 0 ) ROSTERPOS = (WORD)rosterPos;
    }

    return ROSTERPOS;
}
//---------------------------------------------------------------------------
void __fastcall CNLPlayer::setRosterPos( WORD rosterPos )
{
    AnsiString ROSTERPOS = TXT_NULL;
    if ( rosterPos >= ROSTERPOS_MIN && rosterPos <= ROSTERPOS_MAX )
    {
        ROSTERPOS = IntToStr( rosterPos );
    }

    this->_record->ram[ FIELD_ROSTERPOS ] = ROSTERPOS;
}
//---------------------------------------------------------------------------
AnsiString __fastcall CNLPlayer::getRosterPosText()
{
    WORD ROSTERPOS_int = this->RosterPos;
    AnsiString ROSTERPOS_text = TXT_NULL;

    switch ( ROSTERPOS_int )
    {
        case ROSTERPOS_STARTER_C	: ROSTERPOS_text = ROSTERPOS_STARTER_C_TXT; break;
        case ROSTERPOS_STARTER_PF	: ROSTERPOS_text = ROSTERPOS_STARTER_PF_TXT; break;
        case ROSTERPOS_STARTER_SF	: ROSTERPOS_text = ROSTERPOS_STARTER_SF_TXT; break;
        case ROSTERPOS_STARTER_SG	: ROSTERPOS_text = ROSTERPOS_STARTER_SG_TXT; break;
        case ROSTERPOS_STARTER_PG	: ROSTERPOS_text = ROSTERPOS_STARTER_PG_TXT; break;
        case ROSTERPOS_BENCH_1		: ROSTERPOS_text = ROSTERPOS_BENCH_1_TXT; break;
        case ROSTERPOS_BENCH_2		: ROSTERPOS_text = ROSTERPOS_BENCH_2_TXT; break;
        case ROSTERPOS_BENCH_3		: ROSTERPOS_text = ROSTERPOS_BENCH_3_TXT; break;
        case ROSTERPOS_BENCH_4		: ROSTERPOS_text = ROSTERPOS_BENCH_4_TXT; break;
        case ROSTERPOS_BENCH_5		: ROSTERPOS_text = ROSTERPOS_BENCH_5_TXT; break;
        case ROSTERPOS_BENCH_6		: ROSTERPOS_text = ROSTERPOS_BENCH_6_TXT; break;
        case ROSTERPOS_BENCH_7		: ROSTERPOS_text = ROSTERPOS_BENCH_7_TXT; break;
        case ROSTERPOS_INACTIVE_1	: ROSTERPOS_text = ROSTERPOS_INACTIVE_1_TXT; break;
        case ROSTERPOS_INACTIVE_2	: ROSTERPOS_text = ROSTERPOS_INACTIVE_2_TXT; break;
        case ROSTERPOS_INACTIVE_3	: ROSTERPOS_text = ROSTERPOS_INACTIVE_3_TXT; break;
    }
    return ROSTERPOS_text;
}
//---------------------------------------------------------------------------
bool __fastcall CNLPlayer::getInSeason()
{
    bool INSEASON = false;

    if ( this->_record )
    {
        INSEASON = CDBEngine::stringToBool( this->_record->ram[ FIELD_INSEASON ] );
    }

    return INSEASON;
}
//---------------------------------------------------------------------------
double __fastcall CNLPlayer::getOverallRtg()
{
    double OVERALLRTG = 50.0;

    if ( this->_record )
    {
        int OVERALLRTG_int = this->_record->ram[ FIELD_OVERALLRTG ].ToIntDef( 0 );
        OVERALLRTG = 50.0 + ( ((double)OVERALLRTG_int)/2.0 );
    }

    return OVERALLRTG;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getYearsExp()
{
    WORD YEARSEXP = YEARSEXP_UNDEF;

    if ( this->_record )
    {
        YEARSEXP = this->_record->ram[ FIELD_YEARSEXP  ].ToIntDef( YEARSEXP_UNDEF );
    }
    return YEARSEXP;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getInjuryId()
{
    WORD INJURYID = INJURYID_UNDEF;

    if ( this->_record )
    {
        INJURYID = this->_record->ram[ FIELD_INJURYID  ].ToIntDef( INJURYID_UNDEF );
    }
    return INJURYID;
}
//---------------------------------------------------------------------------
bool __fastcall CNLPlayer::getIsPlayable()
{
    bool ISPLAYABLE = false;

    if ( this->_record )
    {
        ISPLAYABLE = CDBEngine::stringToBool( this->_record->ram[ FIELD_ISPLAYABLE ] );
    }

    return ISPLAYABLE;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonGM()
{
    WORD SGM = 0;

    if ( this->_record )
    {
        SGM = this->_record->ram[ FIELD_SGM ].ToIntDef(0);
    }

    return SGM;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonGMS()
{
    WORD SGMS = 0;

    if ( this->_record )
    {
        SGMS = this->_record->ram[ FIELD_SGMS ].ToIntDef(0);
    }

    return SGMS;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonFGM()
{
    WORD SFGM = 0;

    if ( this->_record )
    {
        SFGM = this->_record->ram[ FIELD_SFGM ].ToIntDef(0);
    }

    return SFGM;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonFGA()
{
    WORD SFGA = 0;

    if ( this->_record )
    {
        SFGA = this->_record->ram[ FIELD_SFGA ].ToIntDef(0);
    }

    return SFGA;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeason3PM()
{
    WORD S3PM = 0;

    if ( this->_record )
    {
        S3PM = this->_record->ram[ FIELD_S3PM ].ToIntDef(0);
    }

    return S3PM;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeason3PA()
{
    WORD S3PA = 0;

    if ( this->_record )
    {
        S3PA = this->_record->ram[ FIELD_S3PA ].ToIntDef(0);
    }

    return S3PA;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonFTM()
{
    WORD SFTM = 0;

    if ( this->_record )
    {
        SFTM = this->_record->ram[ FIELD_SFTM ].ToIntDef(0);
    }

    return SFTM;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonFTA()
{
    WORD SFTA = 0;

    if ( this->_record )
    {
        SFTA = this->_record->ram[ FIELD_SFTA ].ToIntDef(0);
    }

    return SFTA;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonORB()
{
    WORD SORB = 0;

    if ( this->_record )
    {
        SORB = this->_record->ram[ FIELD_SORB ].ToIntDef(0);
    }

    return SORB;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonDRB()
{
    WORD SDRB = 0;

    if ( this->_record )
    {
        SDRB = this->_record->ram[ FIELD_SDRB ].ToIntDef(0);
    }

    return SDRB;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonAST()
{
    WORD SAST = 0;

    if ( this->_record )
    {
        SAST = this->_record->ram[ FIELD_SAST ].ToIntDef(0);
    }

    return SAST;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonSTL()
{
    WORD SSTL = 0;

    if ( this->_record )
    {
        SSTL = this->_record->ram[ FIELD_SSTL ].ToIntDef(0);
    }

    return SSTL;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonBLK()
{
    WORD SBLK = 0;

    if ( this->_record )
    {
        SBLK = this->_record->ram[ FIELD_SBLK ].ToIntDef(0);
    }

    return SBLK;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonTO()
{
    WORD STO = 0;

    if ( this->_record )
    {
        STO = this->_record->ram[ FIELD_STO ].ToIntDef(0);
    }

    return STO;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonFLS()
{
    WORD SFLS = 0;

    if ( this->_record )
    {
        SFLS = this->_record->ram[ FIELD_SFLS ].ToIntDef(0);
    }

    return SFLS;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonMIN()
{
    WORD SMIN = 0;

    if ( this->_record )
    {
        SMIN = this->_record->ram[ FIELD_SMIN ].ToIntDef(0);
    }

    return SMIN;
}
//---------------------------------------------------------------------------
WORD __fastcall CNLPlayer::getSeasonEJT()
{
    WORD SEJT = 0;

    if ( this->_record )
    {
        SEJT = this->_record->ram[ FIELD_SEJT ].ToIntDef(0);
    }

    return SEJT;
}
//---------------------------------------------------------------------------
//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================
//===========================================================================

