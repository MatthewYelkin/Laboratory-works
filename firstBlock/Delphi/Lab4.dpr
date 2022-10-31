Program Lab4;

Uses
    System.SysUtils;
Const
    MIN = 1;
    MAX = 100;
Var
    N, I, Sum, LastNum: Integer;
    IsCorrect: Boolean;
    Arr: array of Integer;

begin
    N := 0;
    Sum := 0;
    Writeln('��������� A1+2A2+3A3+...+NAN. �������� ����� - �� 1 �� 100.');
    Repeat
        IsCorrect := True;
        Write('������� N: ');
        Try
            Readln(N);
            Except
            Writeln('������. ������� ���������� �����');
            IsCorrect := False;
        End;
        If IsCorrect and ((N < MIN) or (N > MAX)) Then
        Begin
            Writeln('������. ������� ����� �� 1 �� 100');
            IsCorrect := False;
        End;
    Until (IsCorrect);
    SetLength(Arr, N);
    LastNum := N - 1;
    For I := 0 to LastNum Do
    Begin
        repeat
            Write('������� A', (I + 1), ': ');
            IsCorrect := True;
            try
                Readln(Arr[I]);
            except
                Writeln('������. ������� ���������� �����');
                IsCorrect := False;
            end;
            if IsCorrect and ((Arr[I] < MIN) or (Arr[I] > MAX)) then
            begin
                Writeln('������. ������� ����� �� 1 �� 100');
                IsCorrect := False;
            end;
        until (IsCorrect);
    End;
    For I := 0 to LastNum Do
        Sum := Sum + Arr[I] * (I + 1);
    Writeln('�����: ', Sum);
    Readln;
end.
