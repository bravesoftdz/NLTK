object AcceptChangesDlg: TAcceptChangesDlg
  Left = 0
  Top = 0
  Caption = 'AcceptChangesDlg'
  ClientHeight = 386
  ClientWidth = 660
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object pnlCmd: TPanel
    Left = 0
    Top = 326
    Width = 660
    Height = 60
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitTop = 272
    ExplicitWidth = 511
    object btnAccept: TButton
      Left = 0
      Top = 0
      Width = 89
      Height = 60
      Align = alLeft
      Default = True
      ImageAlignment = iaCenter
      ImageIndex = 191
      Images = IconListsDlg.ilIconSet48x48_green
      ModalResult = 1
      TabOrder = 0
    end
    object btnCancel: TButton
      Left = 571
      Top = 0
      Width = 89
      Height = 60
      Align = alRight
      Cancel = True
      ImageAlignment = iaCenter
      ImageIndex = 191
      Images = IconListsDlg.ilIconSet48x48_red
      ModalResult = 2
      TabOrder = 1
      ExplicitLeft = 422
    end
  end
  object txtChanges: TMemo
    Left = 0
    Top = 0
    Width = 660
    Height = 326
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Liberation Mono'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
    WordWrap = False
    ExplicitWidth = 511
    ExplicitHeight = 272
  end
end
