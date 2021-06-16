object Form4: TForm4
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Form4'
  ClientHeight = 438
  ClientWidth = 662
  Color = 10014360
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = Button2Click
  OnClose = FormClose
  OnShow = Button3Click
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 17
    Top = 173
    Width = 234
    Height = 212
    Proportional = True
  end
  object Edit1: TEdit
    Left = 130
    Top = 45
    Width = 121
    Height = 21
    PasswordChar = '*'
    TabOrder = 0
    Text = #1087#1072#1088#1086#1083#1100
  end
  object Edit2: TEdit
    Left = 130
    Top = 72
    Width = 121
    Height = 21
    PasswordChar = '*'
    TabOrder = 1
    Text = #1087#1072#1088#1086#1083#1100
  end
  object Edit3: TEdit
    Left = 130
    Top = 99
    Width = 121
    Height = 21
    PasswordChar = '*'
    TabOrder = 2
    Text = #1087#1072#1088#1086#1083#1100
  end
  object Button1: TButton
    Left = 152
    Top = 126
    Width = 75
    Height = 25
    Caption = #1057#1084#1077#1085#1080#1090#1100
    TabOrder = 3
    OnClick = Button1Click
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 49
    Width = 116
    Height = 17
    Caption = #1044#1077#1081#1089#1090#1074#1091#1102#1097#1080#1081' '#1087#1072#1088#1086#1083#1100
    TabOrder = 4
  end
  object StaticText2: TStaticText
    Left = 8
    Top = 76
    Width = 76
    Height = 17
    Caption = #1053#1086#1074#1099#1081' '#1087#1072#1088#1086#1083#1100
    TabOrder = 5
  end
  object StaticText3: TStaticText
    Left = 8
    Top = 99
    Width = 98
    Height = 17
    Caption = #1055#1086#1074#1090#1086#1088#1080#1090#1077' '#1087#1072#1088#1086#1083#1100
    TabOrder = 6
  end
  object Button2: TButton
    Left = 8
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 7
    Visible = False
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 416
    Top = 45
    Width = 217
    Height = 292
    Lines.Strings = (
      'Memo1')
    TabOrder = 8
    Visible = False
  end
  object Button3: TButton
    Left = 272
    Top = 144
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 9
    Visible = False
    OnClick = Button3Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1200
    OnTimer = Button3Click
    Left = 400
    Top = 392
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 1100
    OnTimer = Timer2Timer
    Left = 480
    Top = 376
  end
end
