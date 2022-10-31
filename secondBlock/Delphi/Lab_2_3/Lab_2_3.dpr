Program Lab_2_3;

{$APPTYPE CONSOLE}
{$R *.res}

uses
  System.SysUtils;

Type
    TMatrix = Array of Array of Real;
    TRoots = Array of Real;

Function ReadCountRoots(): Integer;
Var
    TmpCountRoots: Integer;
    IsCorrect: Boolean;
Begin
    Repeat
        IsCorrect := True;
        Write('������� ���������� ����������� ������� ���������. �ountRoots = ');
{$I-}
        Readln(TmpCountRoots);
{$I+}
        If (IOResult <> 0) or (TmpCountRoots < 2) then
        Begin
            IsCorrect := False;
            Writeln('������ �����. ���������� ����������� ������� ��������� ����� ����� ������� 1. ');
        End;
    Until IsCorrect;
    ReadCountRoots := TmpCountRoots;
End;

Function ConsolOrFileInput(OutputText: String): Integer;
Var
    ZO: Integer;
    IsCorrect: Boolean;
Begin

    Repeat
        IsCorrect := True;
        Writeln(OutputText);
{$I-}
        Readln(ZO);
{$I+}
        If (IOResult <> 0) or (ZO < 0) or (ZO > 1) then
        Begin
            IsCorrect := False;
            Writeln('������ �����.');
        End;
    Until IsCorrect;
    ConsolOrFileInput := ZO;
End;

Function InputMatrixCell(): Real;
Var
    IsCorrect: Boolean;
    TmpValue: Real;
Begin
    Repeat
        IsCorrect := True;
{$I-}
        Readln(TmpValue);
{$I+}
        If (IOResult <> 0) then
        Begin
            IsCorrect := False;
            Writeln('������ �����. ��������� ����.');
        End;
    Until IsCorrect;
    InputMatrixCell := TmpValue;
End;

Procedure ReadMatrix(TmpCountRoots: Integer; Var TmpMatrix: TMatrix);
Var
    I, J: Integer;
    IsCorrect: Boolean;
Begin
    For I := 0 to TmpCountRoots - 1 do
    Begin
        For J := 0 to TmpCountRoots do
        Begin
            Write('������� ������� ', I + 1, ' ������ � ', J + 1, ' ������� ');
            TmpMatrix[I, J] := InputMatrixCell();
        End;
    End;
End;

Procedure WriteRoots(TmpCountRoots: Integer; TmpRoots: TRoots);
Var
    I: Integer;
Begin
    Write('����� ��������� ����� ');
    For I := 0 to TmpCountRoots - 1 do
        Write(TmpRoots[I]:5:2, ' ');
    Writeln;
End;

Function FileExist(FileName: String): Boolean;
Var
    F: Text;
Begin
{$I-}
    Assign(F, FileName);
    Reset(F);
{$I+}
    Result := (IOResult = 0) and (FileName <> '');
    if Result then
        Close(F);
End;

Function InputFilePach(): String;
Var
    IsCorrect: Boolean;
    FilePach: String;
Begin
    Repeat
        Writeln('������� ���� � ����� � �������� �����.');
        IsCorrect := True;
        Readln(FilePach);
        If FileExist(FilePach) = False then
        Begin
            Writeln('������ ����� ����� �����.');
            IsCorrect := False;
        End;
    Until IsCorrect;
    InputFilePach := FilePach;
End;

Procedure InputFromFile(Var TmpCountRoots: Integer; Var TmpMatrix: TMatrix);
Var
    I, J: Integer;
    IsCorrect: Boolean;
    F: Text;
Begin
    Assign(F, InputFilePach());
    Reset(F);
{$I-}
    Read(F, TmpCountRoots);
{$I+}
    If (IOResult <> 0) or (TmpCountRoots < 2) then
    Begin
        IsCorrect := False;
        Writeln('������ �����. ������� ���������� ����������� ������ 1 c ����������.');
        TmpCountRoots := ReadCountRoots();
    End;
    SetLength(TmpMatrix, TmpCountRoots, TmpCountRoots + 1);
    For I := 0 to TmpCountRoots - 1 do
    Begin
        For J := 0 to TmpCountRoots do
        Begin
{$I-}
            Read(F, TmpMatrix[I, J]);
{$I+}
            If (IOResult <> 0) then
            Begin
                Write('������ ������ ����������� �� �����. ������� ���������� ',
                       I + 1, ' ������ ', J + 1, ' ������� � ���������� : ');
                TmpMatrix[I, J] := InputMatrixCell();
            End;
        End;
    End;
    Close(F);
End;

Procedure WriteMatrixInConsol(TmpCountRoots: Integer; TmpMatrix: TMatrix);
Var
    I, J: Integer;
Begin
    Writeln('�� ����� ������� :');
    For I := 0 to TmpCountRoots - 1 do
    Begin
        For J := 0 to TmpCountRoots do
            Write(TmpMatrix[I, J]:5:2, ' ');
        Writeln;
    End;
End;

Procedure MoveStrings(Var TmpMatrix: TMatrix; FirstRow, SecondRow: Integer;
                      TmpCountRoots: Integer);
Var
    J: Integer;
    R: Real;
Begin
    If (FirstRow < TmpCountRoots + 1) and (SecondRow < TmpCountRoots + 1) then
    Begin
        For J := 0 to TmpCountRoots do
        Begin
            R := TmpMatrix[SecondRow, J];
            TmpMatrix[SecondRow, J] := TmpMatrix[FirstRow, J];
            TmpMatrix[FirstRow, J] := R;
        End;
    End
End;

Procedure NewMatrix(TmpCountRoots: Integer; TmpMatrix: TMatrix);
Var
    I, J, M, TmpI: Integer;
    K: Real;
Begin
    For J := 0 to TmpCountRoots - 1 do
    Begin
        If TmpMatrix[J, J] = 0 then
        Begin
            TmpI := J + 1;
            Repeat
                If TmpMatrix[TmpI, J] <> 0 then
                    MoveStrings(TmpMatrix, J, TmpI, TmpCountRoots);
            Until ((TmpI < TmpCountRoots + 1) or (TmpMatrix[J, J] <> 0));
        End;
        For I := J + 1 to TmpCountRoots - 1 do
        Begin
            K := TmpMatrix[I, J] / TmpMatrix[J, J];
            For M := J to TmpCountRoots do
                TmpMatrix[I, M] := TmpMatrix[I, M] - K * TmpMatrix[J, M];
        End;
    End;
End;

Procedure FindRoots(TmpCountRoots: Integer; TmpMatrix: TMatrix;
  Var TmpRoots: TRoots);
Var
    I, J: Integer;
    Sum: Real;
Begin
    SetLength(TmpRoots, TmpCountRoots);
    For I := TmpCountRoots - 1 downto 0 do
    Begin
        Sum := 0;
        For J := I + 1 to TmpCountRoots - 1 do
            Sum := Sum + TmpRoots[J] * TmpMatrix[I, J];
        If TmpMatrix[I, I] = 0 then
            TmpRoots[I] := 0
        Else
            TmpRoots[I] := (TmpMatrix[I, TmpCountRoots] - Sum) /
              TmpMatrix[I, I];
    End;
End;

Procedure TheGaussM(TmpCountRoots: Integer; TmpMatrix: TMatrix;
  Var TmpRoots: TRoots);
Begin
    WriteMatrixInConsol(TmpCountRoots, TmpMatrix);
    NewMatrix(TmpCountRoots, TmpMatrix);
    FindRoots(TmpCountRoots, TmpMatrix, TmpRoots);
End;

Procedure OutputInFile(TmpCountRoots: Integer; TmpRoots: TRoots);
Var
    I: Integer;
    F: Text;
    SaveFile: String;
    IsCorrect: Boolean;
Begin
    If ConsolOrFileInput
      ('�� ������ ��������� ��������� ��������� � ����?(0 - ��/ 1 - ���).') = 0 then
    Begin
        SaveFile := InputFilePach();
        Assign(F, SaveFile);
        Rewrite(F);
        Write(F, '����� ��������� ����� ');
        For I := 0 to TmpCountRoots - 1 do
        Begin
            Write(F, TmpRoots[I]:5:2, ' ');
        End;
        Close(F);
        Writeln('����� ��������� � ���� : ', SaveFile);
        Readln;
    End;
End;

Procedure ConsolInput(Var TmpCountRoots: Integer; Var TmpMatrix: TMatrix);
Begin
    TmpCountRoots := ReadCountRoots();
    SetLength(TmpMatrix, TmpCountRoots, TmpCountRoots + 1);
    ReadMatrix(TmpCountRoots, TmpMatrix);
End;

Procedure Input(Var TmpCountRoots: Integer; Var TmpMatrix: TMatrix);
begin
    If ConsolOrFileInput
      ('������� 0, ���� ������ �������� � �������, 1 , ���� � �����.') = 0 then
        ConsolInput(TmpCountRoots, TmpMatrix)
    Else
        InputFromFile(TmpCountRoots, TmpMatrix);
end;

Procedure Main();
Var
    Matrix: TMatrix;
    Roots: TRoots;
    CountRoots: Integer;
Begin
    Writeln('������ ��������� ��������� "������ ���" � ������� ������� �������������� ��������� ������� ������.');
    Writeln('���������� : ���� ����� �������� ������ ��� ������, ������������ ������� ������� �� ����.������� ����� ������ ������ ���������, ��� ������������ ������� �� ����.');
    Input(CountRoots, Matrix);
    TheGaussM(CountRoots, Matrix, Roots);
    WriteRoots(CountRoots, Roots);
    OutputInFile(CountRoots, Roots);
End;

Begin
    Main();
End.

