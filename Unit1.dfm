object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'TForm1'
  ClientHeight = 485
  ClientWidth = 835
  Color = 10014360
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 294
    Top = 295
    Width = 3
    Height = 13
  end
  object Button1: TButton
    Left = 405
    Top = 211
    Width = 75
    Height = 25
    Caption = #1042#1086#1081#1090#1080
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 286
    Top = 184
    Width = 113
    Height = 21
    TabOrder = 1
    Text = #1051#1086#1075#1080#1085
  end
  object Edit2: TEdit
    Left = 286
    Top = 211
    Width = 113
    Height = 21
    Align = alCustom
    PasswordChar = '*'
    TabOrder = 2
    Text = #1087#1072#1088#1086#1083#1100'$'#8470'4'
  end
  object Memo1: TMemo
    Left = 8
    Top = 336
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    TabOrder = 3
    Visible = False
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 640
    Top = 328
  end
end
