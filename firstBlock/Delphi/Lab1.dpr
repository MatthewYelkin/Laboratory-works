program Lab1;
uses
    System.SysUtils;
var
    Number: Integer;
    IsCorrect: Boolean;
begin
    Writeln('������� ����� ��� ������(����� �� 1 �� 7)');
    Repeat
        IsCorrect := True;
        try
            Readln(Number);
        except
            Writeln('������. ��������� ������������ ��������� ������');
            IsCorrect := False;
        end;
        if (IsCorrect) and (Number < 1) or (Number > 7) then
        begin
            Writeln('������. ������� ����� �� 1 �� 7!');
            IsCorrect := False;
        end;
    Until (IsCorrect);
    case Number of
        1: Writeln('�����������');
        2: Writeln('�������');
        3: Writeln('�����');
        4: Writeln('�������');
        5: Writeln('�������');
        6: Writeln('�������');
        7: Writeln('�����������');
    end;
    Readln;
end.
