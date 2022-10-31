program Lab3;

uses
  System.SysUtils;

Var
    M, N, K, Mult: Integer;
    IsCorrect: Boolean;

Begin
    Writeln('���� ��� ����������� ����� m � n (1<m<n). ����� ���������� k, ��� ������� m^k>n');
    IsCorrect := True;
    Repeat
        Repeat
            IsCorrect := True;
            Write('������� m = ');
            Try
                Readln(M);
            Except
                Writeln('������. ������� ���������� �����');
                IsCorrect := False;
            End;
        Until (IsCorrect);
        Repeat
            IsCorrect := True;
            Write('������� n = ');
            Try
                Readln(N);
            Except
                Writeln('������. ������� ���������� �����');
                IsCorrect := False;
            End;
        Until (IsCorrect);
        If (M < 2) or (M > N - 1) Then
        Begin
            Writeln('������. ������ ����������� ������� 1<m<n');
            IsCorrect := False;
        End;
    Until (IsCorrect);
    Mult := 1;
    K := 0;
    while Mult < N + 1 do
    Begin
        Mult := Mult * M;
        K := K + 1;
    End;
    Writeln('���������� k, ��� ������� m^k>n: ', K);
    Readln;
End.
