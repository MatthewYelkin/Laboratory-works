Program Lab_2_3;

Uses
    System.SysUtils;

Type
    TMatrix = Array of Array of Real;
    TRoots = Array of Real;

Function ReadCountRoots(): Integer;
Const
    MIN_COUNT = 2;
    MAX_COUNT = 10;
Var
    TmpCountRoots: Integer;
    IsCorrect: Boolean;
Begin
    Repeat
        IsCorrect := True;
        Write('������� ���������� ����������� ������� ���������: ');
        Try
            Readln(TmpCountRoots);
        Except
            IsCorrect := False;
            Writeln('������ �����. ���������� ����������� ������� ��������� ����� �����.');
        End;
        If (IsCorrect) and ((TmpCountRoots < MIN_COUNT) or (TmpCountRoots > MAX_COUNT)) Then
        Begin
            IsCorrect := False;
            Writeln('������ �����. ���������� ����������� ������� ��������� ����� �����. �������� ����� �� 2 �� 10.');
        End;
    Until IsCorrect;
    ReadCountRoots := TmpCountRoots;
End;

Function TakeChoice(OutputText: String): Integer;
Var
    Choice: Integer;
    IsCorrect: Boolean;
Begin
    Repeat
        IsCorrect := True;
        Writeln(OutputText);
        Try
            Readln(Choice);
        Except
            IsCorrect := False;
            Writeln('������� ������������ ������');
        End;
        If (IsCorrect) And ((Choice < 0) Or (Choice > 1)) then
        Begin
            IsCorrect := False;
            Writeln('������� 0 ��� 1.');
        End;
    Until IsCorrect;
    TakeChoice := Choice;
End;

Function InputMatrixCell(): Real;
Const
    MIN_VALUE = -5000;
    MAX_VALUE = 5000;
Var
    IsCorrect: Boolean;
    TmpValue: Real;
Begin
    Repeat
        IsCorrect := True;
        Try
            Readln(TmpValue);
        Except
            IsCorrect := False;
            Writeln('������ �����. ������� ������������ ������');
        End;
        If (IsCorrect) And ((TmpValue < MIN_VALUE) Or (TmpValue > MAX_VALUE)) then
        Begin
            IsCorrect := False;
            Writeln('������! �������� ����� �� -5000 �� 5000.');
        End;
    Until IsCorrect;
    InputMatrixCell := TmpValue;
End;

Procedure ReadMatrix(TmpCountRoots: Integer; Var TmpMatrix: TMatrix);
Var
    I, J: Integer;
Begin
    For I := 0 to TmpCountRoots - 1 do
    Begin
        For J := 0 to TmpCountRoots do
        Begin
            Write('������� ������� ', I + 1, ' ������ � ', J + 1, ' ������� ');
            TmpMatrix[I][J] := InputMatrixCell();
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

Function InputFilePath(): String;
Var
    IsCorrect: Boolean;
    FilePath: String;
Begin
    Repeat
        Writeln('������� ���� � ����� � ��� ��������.');
        IsCorrect := True;
        Readln(FilePath);
        If not FileExists(FilePath) then
        Begin
            Writeln('������ ����� ����� �����.');
            IsCorrect := False;
        End;
    Until IsCorrect;
    InputFilePath := FilePath;
End;

Procedure InputFromFile(Var TmpCountRoots: Integer; Var TmpMatrix: TMatrix);
Const
    MIN_COUNT = 2;
    MAX_COUNT = 10;
    MIN_VALUE = -5000;
    MAX_VALUE = 5000;
Var
    I, J, LastNum: Integer;
    F: Text;
Begin
    Assign(F, InputFilePath());
    Reset(F);
    Try
        Readln(F, TmpCountRoots);
    Except
        Writeln('������ �����. ������� ���������� ����������� c ����������.');
        TmpCountRoots := ReadCountRoots();
    End;
    If (TmpCountRoots < MIN_COUNT) Or (TmpCountRoots > MAX_COUNT) Then
    Begin
        Writeln('������ �����. ������� ���������� ����������� c ����������.');
        TmpCountRoots := ReadCountRoots();
    End;
    SetLength(TmpMatrix, TmpCountRoots, TmpCountRoots + 1);
    LastNum := TmpCountRoots - 1;
    For I := 0 To LastNum Do
    Begin
        For J := 0 To TmpCountRoots Do
        Begin
            Try
                Read(F, TmpMatrix[I, J]);
            Except
                Write('������ ������ ����������� �� �����. ������� ���������� ',
                       I + 1, ' ������ ', J + 1, ' ������� � ���������� : ');
                TmpMatrix[I][J] := InputMatrixCell();
            End;
            If (TmpMatrix[I][J] < MIN_VALUE) Or (TmpMatrix[I][J] > MAX_VALUE) Then
            Begin
                Write('������ ������ ����������� �� �����. ������� ���������� ',
                       I + 1, ' ������ ', J + 1, ' ������� � ���������� : ');
                TmpMatrix[I][J] := InputMatrixCell();
            End;
        End;
    End;
    Close(F);
End;

Procedure WriteMatrixInConsol(TmpCountRoots: Integer; TmpMatrix: TMatrix);
Var
    I, J, LastNum: Integer;
Begin
    LastNum := TmpCountRoots - 1;
    Writeln('�� ����� ������� :');
    For I := 0 To LastNum Do
    Begin
        For J := 0 To TmpCountRoots Do
            Write(TmpMatrix[I][J]:5:2, ' ');
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
            R := TmpMatrix[SecondRow][J];
            TmpMatrix[SecondRow][J] := TmpMatrix[FirstRow][J];
            TmpMatrix[FirstRow][J] := R;
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
        If TmpMatrix[J][J] = 0 then
        Begin
            TmpI := J + 1;
            Repeat
                If (TmpMatrix[TmpI][J] <> 0) Then
                    MoveStrings(TmpMatrix, J, TmpI, TmpCountRoots);
            Until ((TmpI < TmpCountRoots + 1) or (TmpMatrix[J][J] <> 0));
        End;
        For I := J + 1 To TmpCountRoots - 1 Do
        Begin
            K := TmpMatrix[I][J] / TmpMatrix[J][J];
            For M := J To TmpCountRoots Do
                TmpMatrix[I][M] := TmpMatrix[I][M] - K * TmpMatrix[J][M];
        End;
    End;
End;

Procedure FindRoots(TmpCountRoots: Integer; TmpMatrix: TMatrix; Var TmpRoots: TRoots);
Var
    I, J: Integer;
    Sum: Real;
Begin
    SetLength(TmpRoots, TmpCountRoots);
    For I := TmpCountRoots - 1 DownTo 0 Do
    Begin
        Sum := 0;
        For J := I + 1 To TmpCountRoots - 1 Do
            Sum := Sum + TmpRoots[J] * TmpMatrix[I][J];
        If TmpMatrix[I][I] = 0 Then
            TmpRoots[I] := 0
        Else
            TmpRoots[I] := (TmpMatrix[I][TmpCountRoots] - Sum) / TmpMatrix[I][I];
    End;
End;

Procedure GaussM(TmpCountRoots: Integer; TmpMatrix: TMatrix;
  Var TmpRoots: TRoots);
Begin
    WriteMatrixInConsol(TmpCountRoots, TmpMatrix);
    NewMatrix(TmpCountRoots, TmpMatrix);
    FindRoots(TmpCountRoots, TmpMatrix, TmpRoots);
End;

Procedure OutputInFile(TmpCountRoots: Integer; TmpRoots: TRoots);
Var
    I, LastNum: Integer;
    F: Text;
    SaveFile: String;
Begin
    LastNum := TmpCountRoots - 1;
    If TakeChoice('�� ������ ��������� ��������� ��������� � ����?(0 - ��/ 1 - ���).') = 0 Then
    Begin
        SaveFile := InputFilePath();
        Assign(F, SaveFile);
        Rewrite(F);
        Write(F, '����� ��������� �����: ');
        For I := 0 To LastNum Do
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
    If TakeChoice('������� 0, ���� ������ ������� ���������� �� �������, 1 , ���� �� �����.') = 0 then
        ConsolInput(TmpCountRoots, TmpMatrix)
    Else
        InputFromFile(TmpCountRoots, TmpMatrix);
end;

Procedure PrintTaskInfo();
Begin
    Writeln('������ ��������� ��������� "������ ���" � ������� ������� �������������� ��������� ������� ������.');
    Writeln('���������� : ���� ����� �������� ������ ��� ������, ������������ ������� ������� �� ����.');
End;

Var
    Matrix: TMatrix;
    Roots: TRoots;
    CountRoots: Integer;
Begin
    PrintTaskInfo();
    Input(CountRoots, Matrix);
    GaussM(CountRoots, Matrix, Roots);
    WriteRoots(CountRoots, Roots);
    OutputInFile(CountRoots, Roots);
End.
