object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'TForm2'
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
  OnShow = Button3Click
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 464
    Top = 280
    Width = 171
    Height = 181
    Proportional = True
  end
  object Button1: TButton
    Left = 321
    Top = 109
    Width = 145
    Height = 33
    Caption = #1057#1084#1077#1085#1080#1090#1100' '#1087#1072#1088#1086#1083#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 28
    Width = 145
    Height = 33
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 67
    Width = 145
    Height = 37
    Caption = #1057#1087#1080#1089#1086#1082' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 110
    Width = 145
    Height = 32
    Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
    TabOrder = 3
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 321
    Top = 28
    Width = 145
    Height = 21
    PasswordChar = '*'
    TabOrder = 4
    Text = #1087#1072#1088#1086#1083#1100
  end
  object Edit2: TEdit
    Left = 321
    Top = 55
    Width = 145
    Height = 21
    PasswordChar = '*'
    TabOrder = 5
    Text = #1087#1072#1088#1086#1083#1100
  end
  object Edit3: TEdit
    Left = 321
    Top = 82
    Width = 145
    Height = 21
    PasswordChar = '*'
    TabOrder = 6
    Text = #1087#1072#1088#1086#1083#1100
  end
  object StaticText1: TStaticText
    Left = 190
    Top = 32
    Width = 116
    Height = 17
    Caption = #1044#1077#1081#1089#1090#1074#1091#1102#1097#1080#1081' '#1087#1072#1088#1086#1083#1100
    TabOrder = 7
  end
  object StaticText2: TStaticText
    Left = 230
    Top = 55
    Width = 76
    Height = 17
    Caption = #1053#1086#1074#1099#1081' '#1087#1072#1088#1086#1083#1100
    TabOrder = 8
  end
  object StaticText3: TStaticText
    Left = 174
    Top = 82
    Width = 133
    Height = 17
    Caption = #1055#1086#1074#1090#1086#1088#1080#1090#1077' '#1085#1086#1074#1099#1081' '#1087#1072#1088#1086#1083#1100
    TabOrder = 9
  end
  object Memo1: TMemo
    Left = 8
    Top = 208
    Width = 241
    Height = 269
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    TabOrder = 10
  end
  object Edit4: TEdit
    Left = 296
    Top = 208
    Width = 121
    Height = 21
    TabOrder = 11
  end
  object Button6: TButton
    Left = 326
    Top = 235
    Width = 91
    Height = 25
    Caption = #1047#1072#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 12
    OnClick = Button6Click
  end
  object Button5: TButton
    Left = 326
    Top = 266
    Width = 91
    Height = 25
    Caption = #1056#1072#1079#1073#1083#1086#1082#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 13
    OnClick = Button5Click
  end
  object Button7: TButton
    Left = 423
    Top = 206
    Width = 129
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1077#1090#1083#1103
    TabOrder = 14
    OnClick = Button7Click
  end
  object CheckBox1: TCheckBox
    Left = 512
    Top = 36
    Width = 187
    Height = 17
    Caption = #1057#1084#1077#1085#1072' '#1087#1072#1088#1086#1083#1103' '#1087#1088#1080' '#1087#1077#1088#1074#1086#1084' '#1074#1093#1086#1076#1077
    Checked = True
    State = cbChecked
    TabOrder = 15
  end
  object CheckBox2: TCheckBox
    Left = 512
    Top = 109
    Width = 305
    Height = 17
    Caption = ' '#1059#1089#1090#1072#1085#1086#1074#1083#1077#1085#1080#1077' '#1084#1080#1085#1080#1084#1072#1083#1100#1085#1086#1075#1086' '#1089#1088#1086#1082#1072' '#1076#1077#1081#1089#1090#1080#1074#1080#1103' '#1087#1072#1088#1086#1083#1103
    Checked = True
    State = cbChecked
    TabOrder = 16
  end
  object CheckBox3: TCheckBox
    Left = 512
    Top = 59
    Width = 337
    Height = 17
    Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1085#1080#1077' '#1079#1072#1076#1077#1088#1078#1082#1080' '#1087#1088#1080' '#1074#1074#1086#1076#1077' '#1085#1077#1087#1088#1072#1074#1080#1083#1100#1085#1086#1075#1086' '#1087#1072#1088#1086#1083#1103
    Checked = True
    State = cbChecked
    TabOrder = 17
  end
  object Edit5: TEdit
    Left = 512
    Top = 82
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 18
    Text = '5'
  end
  object StringGrid1: TStringGrid
    Left = 641
    Top = 445
    Width = 34
    Height = 32
    DefaultColWidth = 32
    DefaultRowHeight = 32
    FixedColor = clAqua
    FixedCols = 0
    FixedRows = 0
    GradientEndColor = clYellow
    GradientStartColor = clMaroon
    GridLineWidth = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goAlwaysShowEditor, goFixedColClick, goFixedRowClick]
    ScrollBars = ssNone
    TabOrder = 19
    Visible = False
  end
  object Button9: TButton
    Left = 730
    Top = 421
    Width = 83
    Height = 25
    Caption = #1047#1072#1096#1080#1092#1088#1086#1074#1072#1090#1100
    TabOrder = 20
    OnClick = Button9Click
  end
  object StringGrid2: TStringGrid
    Left = 641
    Top = 240
    Width = 176
    Height = 175
    DefaultColWidth = 32
    DefaultRowHeight = 32
    FixedColor = clAqua
    FixedCols = 0
    FixedRows = 0
    GradientEndColor = clYellow
    GradientStartColor = clMaroon
    GridLineWidth = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goAlwaysShowEditor, goFixedColClick, goFixedRowClick]
    ScrollBars = ssNone
    TabOrder = 21
  end
  object Button10: TButton
    Left = 641
    Top = 421
    Width = 83
    Height = 25
    Caption = #1056#1072#1089#1096#1080#1092#1088#1086#1074#1072#1090#1100
    TabOrder = 22
    OnClick = Button10Click
  end
  object Memo2: TMemo
    Left = 166
    Top = 313
    Width = 83
    Height = 164
    Lines.Strings = (
      'Memo2')
    TabOrder = 23
    Visible = False
  end
  object StringGrid3: TStringGrid
    Left = 681
    Top = 445
    Width = 32
    Height = 32
    DefaultColWidth = 32
    DefaultRowHeight = 32
    FixedColor = clAqua
    FixedCols = 0
    FixedRows = 0
    GradientEndColor = clYellow
    GradientStartColor = clMaroon
    GridLineWidth = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goAlwaysShowEditor, goFixedColClick, goFixedRowClick]
    ScrollBars = ssNone
    TabOrder = 24
    Visible = False
  end
  object Memo3: TMemo
    Left = 255
    Top = 297
    Width = 198
    Height = 180
    Lines.Strings = (
      'Memo3')
    TabOrder = 25
  end
  object Button8: TButton
    Left = 423
    Top = 237
    Width = 129
    Height = 23
    Caption = #1057#1084#1077#1085#1080#1090#1100' '#1072#1074#1072#1090#1072#1088
    TabOrder = 26
  end
  object OpenDialog1: TOpenDialog
    Left = 720
    Top = 448
  end
end
