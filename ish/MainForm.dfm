object GETsumN5: TGETsumN5
  Left = 786
  Top = 326
  BorderStyle = bsToolWindow
  Caption = 'GETsumN5'
  ClientHeight = 264
  ClientWidth = 286
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    286
    264)
  PixelsPerInch = 120
  TextHeight = 16
  object Kanji: TImage
    Left = 0
    Top = -16
    Width = 281
    Height = 166
    Anchors = [akLeft, akTop, akBottom]
    Transparent = True
  end
  object Label1: TLabel
    Left = 216
    Top = 0
    Width = 56
    Height = 24
    Caption = 'Label1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 24
    Width = 56
    Height = 24
    Caption = 'Label2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -18
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 112
    Top = 8
    Width = 41
    Height = 16
    Caption = 'Label3'
  end
  object Button1: TButton
    Left = 0
    Top = 168
    Width = 140
    Height = 40
    Anchors = [akLeft, akBottom]
    Caption = 'Button1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 168
    Width = 140
    Height = 40
    Anchors = [akLeft, akBottom]
    Caption = 'Button2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 211
    Width = 140
    Height = 40
    Anchors = [akLeft, akBottom]
    Caption = 'Button3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 144
    Top = 211
    Width = 140
    Height = 40
    Anchors = [akLeft, akBottom]
    Caption = 'Button4'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button4Click
  end
  object ProgressBar1: TProgressBar
    Left = 0
    Top = 249
    Width = 281
    Height = 15
    Anchors = [akLeft, akBottom]
    Min = 0
    Max = 103
    TabOrder = 4
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 32
    Width = 265
    Height = 25
    ColCount = 16
    DefaultColWidth = 15
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 5
  end
  object ProgressBar2: TProgressBar
    Left = 8
    Top = 64
    Width = 21
    Height = 68
    Min = 0
    Max = 5
    Orientation = pbVertical
    TabOrder = 6
  end
end
