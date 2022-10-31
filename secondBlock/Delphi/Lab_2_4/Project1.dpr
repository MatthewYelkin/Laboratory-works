Program Lab_2_4;

uses
    System.SysUtils;

Type
    TMatrix = Array of Array of Integer;

Function InputPathToFile(): String;
Var
    IsCorrect: Boolean;
    Path: String;
Begin
    Repeat
        IsCorrect := True;
        Readln(Path);
        If (not FileExists(Path)) then
        Begin
            IsCorrect := False;
            Writeln('������! ���� � ����� ������ �� ������. ��������� ������� �����.');
        End;
    Until (IsCorrect);
    InputPathToFile := Path;
End;

Procedure PrintMatrixInConsole(Matrix: TMatrix; N: Integer);
Var
    I, J, LastNum: Integer;
Begin
    LastNum := N - 1;

    For I := 0 to LastNum do
    Begin
        For J := 0 to LastNum do
            Write(Matrix[I][J], '  ');
        Writeln;
    End;
End;

Procedure PrintInfoInFile(Matrix, NewMatrix: TMatrix; N: Integer);
Var
    I, J, LastNum: Integer;
    OtpPath: String;
    OtpFile: TextFile;
Begin
    LastNum := N - 1;
    Writeln('������� ��� ����� ��� ������: ');
    OtpPath := InputPathToFile();
    AssignFile(OtpFile, OtpPath);
    Rewrite(OtpFile);
    Writeln(OtpFile, '�������� ���� �������: ');
    For I := 0 to LastNum do
    Begin
        For J := 0 to LastNum do
        Begin
            Write(OtpFile, Matrix[I][J], '  ');
        End;
        Writeln(OtpFile);
    End;
    Writeln(OtpFile, '����� �������:');
    For I := 0 to LastNum Do
    Begin
        For J := 0 to LastNum Do
            Write(OtpFile, NewMatrix[I][J], '  ');
        Writeln(OtpFile);
    End;
    Writeln('������ � ���� ��������� �������.');
    CloseFile(OtpFile);
End;

Function GetResult(Matrix: TMatrix; N: Integer): TMatrix;
Var
    I, J, LastNum, LastNum1: Integer;
    NewMatrix: TMatrix;
Begin
    SetLength(NewMatrix, N, N);
    LastNum := N div 2;
    LastNum1 := LastNum - 1;
    Dec(N);
    For I := 0 to LastNum1 Do
    Begin
        For J := 0 to LastNum1 Do
            NewMatrix[I][J] := Matrix[I + LastNum][j + LastNum];
        For J := LastNum to N Do
            NewMatrix[I][J] := Matrix[I + LastNum][J - LastNum];
    End;
    For I := LastNum to N Do
    Begin
        For J := 0 to LastNum1 Do
            NewMatrix[I][J] := matrix[I - LastNum][J];
        For J := LastNum to N Do
            NewMatrix[I][J] := Matrix[I - LastNum][J];
    End;
    GetResult := NewMatrix;
End;

Function GetOrderFromConsole(): Integer;
Var
    N: Integer;
    IsCorrect: Boolean;
Begin
    Writeln('������� ������� ������� n: ');
    Repeat
        IsCorrect := True;
        Try
            Readln(N);
        Except
            IsCorrect := False;
            Writeln('������! ������� �����!');
        End;
        If (IsCorrect) and ((N < 2) or (N mod 2 <> 0)) Then
        Begin
            IsCorrect := False;
            Writeln('������! ������� ������ ����������� ����� �� ������ 2!');
        End;
    Until (IsCorrect) ;
    GetOrderFromConsole := N;
End;

Function GetMatrixFromConsole(N: Integer): TMatrix;
Const
    MAX = 10000;
    MIN = -10000;
Var
    I, J, LastNum: Integer;
    Matrix: TMatrix;
    IsCorrect: Boolean;
Begin
    SetLength(Matrix, N, N);
    LastNum := N - 1;
    For I := 0 to LastNum do
    Begin
        For J := 0 to LastNum do
        Begin
            Repeat
            IsCorrect := True;
            Writeln('������� �������� �������� a', I+1, J+1, ': ');
                Try
                    Readln(Matrix[I][J]);
                Except
                    IsCorrect := False;
                    Writeln('������! ������� ����� ����� � ��������� �������.');
                End;
                If IsCorrect and ((Matrix[I][J] < MIN) or (Matrix[I][J] > MAX)) Then
                Begin
                    IsCorrect := False;
                    Writeln('������! ������� ����� � ��������� �� -10000 �� 10000.');
                End;
            Until (IsCorrect);
        End;
    End;
    GetMatrixFromConsole := Matrix;
End;

Function GetMatrixFromFile(InpPath: String; N: Integer): TMatrix;
Const
    MAX = 10000;
    MIN = -10000;
Var
    Matrix: TMatrix;
    I, J, LastNum: Integer;
    InpFile: TextFile;
    IsCorrect: Boolean;
Begin
    SetLength(Matrix, N, N);
    LastNum := N - 1;
    AssignFile(InpFile, InpPath);
    Reset(InpFile);
    Readln(InpFile);
    For I := 0 to LastNum do
    Begin
        For J := 0 to LastNum do
        Begin
            Try
                Read(InpFile, Matrix[I][J]);
            Except
                Writeln('� ����� ������� �������� �������� �������� �', I + 1, J + 1, '. ������� ��� � �������.');
                Repeat
                    IsCorrect := True;
                    Writeln('������� �������� �������� a', I+1, J+1, ': ');
                Try
                    Readln(Matrix[I][J]);
                Except
                    IsCorrect := False;
                    Writeln('������! ������� ����� ����� � ��������� �������.');
                End;
                If IsCorrect and ((Matrix[I][J] < MIN) or (Matrix[I][J] > MAX)) Then
                Begin
                    IsCorrect := False;
                    Writeln('������! ������� ����� � ��������� �� -10000 �� 10000.');
                End;
                Until (IsCorrect);
            End
        End;
    End;
    GetMatrixFromFile := Matrix;
    CloseFile(InpFile);
End;

Function GetOrderFromFile(InpPath: String): Integer;
Var
    InpFile: TextFile;
    N: Integer;
Begin
    AssignFile(InpFile, InpPath);
    Reset(InpFile);
    Try
        Readln(InpFile, N);
    Except
        Writeln('������! � ����� ������� ������������ ����������. ������� ������� � �������.');
        N := GetOrderFromConsole();
    End;
    If (N < 2) or (N mod 2 <> 0) then
    Begin
        Writeln('������! ������� ������ ���� ������ ����������� ������ �� ������� 2! ������� ������� � �������.');
        N := GetOrderFromConsole();
    End;
    CloseFile(InpFile);
    GetOrderFromFile := N;
End;

Function GetChoice(): Byte;
Var
    ChosenInput: Byte;
    IsCorrect: Boolean;
Begin
    Repeat
        IsCorrect := True;
        Try
            Readln(ChosenInput);
        Except
            IsCorrect := False;
            Writeln('������! ������� 1 ��� 2.');
        End;
        If ((IsCorrect) and (ChosenInput <> 1) and (ChosenInput <> 2)) then
        Begin
            IsCorrect := False;
            Writeln('������! ������� 1 ��� 2.');
        End;
    Until (IsCorrect);
    GetChoice := ChosenInput;
End;

Procedure OutputOfTaskInfo();
Begin
    Writeln('���� �������������� ���������� ������� ������� 2n. ������� ���������� ���������� ������� n: 1 2');
    Writeln('                                                                                            3 4');
    Writeln('�������� ����� �������: 4 3');
    Writeln('                        1 2');
    Writeln('����� 2n ������ ���� ������ � �� ������ 2!');
End;

Function ChooseMatrix(Choice: Byte; var N: Integer): TMatrix;
Var
    Matrix: TMatrix;
    InpPath: String;
Begin
    If (Choice = 1) then
    Begin
        N := GetOrderFromConsole();
        Matrix := GetMatrixFromConsole(N);
    End
    Else
    Begin
        Writeln('������� ���� ����� ��� ������ �������: ');
        InpPath := InputPathToFile();
        N := GetOrderFromFile(InpPath);
        Matrix := GetMatrixFromFile(InpPath, N);
    End;
    ChooseMatrix := Matrix;
End;

Procedure OutputOfInfo(Choice: Byte; N: Integer; Matrix, NewMatrix: TMatrix);
Begin
    If (Choice = 1) then
    Begin
        Writeln('����� �������:');
        PrintMatrixInConsole(NewMatrix, N);
    End
    Else
        PrintInfoInFile(Matrix, NewMatrix, N);
End;

Var
    ChoiceForInput, ChoiceForOutput: Byte;
    N: Integer;
    Matrix: TMatrix;
    NewMatrix: TMatrix;

Begin
    OutputOfTaskInfo();
    Write('�� ������ ������� ������� ������� (1) ��� ������� � �� ����� (2) ? ');
    ChoiceForInput := GetChoice();
    Matrix := ChooseMatrix(ChoiceForInput, N);
    Writeln('�������� ���� �������: ');
    PrintMatrixInConsole(Matrix, N);
    NewMatrix := GetResult(Matrix, N);
    Write('�� ������ ������� ���������� � ������� (1) ��� � ���� (2) ? ');
    ChoiceForOutput := GetChoice();
    OutputOfInfo(ChoiceForOutput, N, Matrix, NewMatrix);
    Readln;
End.