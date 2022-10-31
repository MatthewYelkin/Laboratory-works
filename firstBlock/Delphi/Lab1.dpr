program Lab1;
uses
    System.SysUtils;
var
    Number: Integer;
    IsCorrect: Boolean;
begin
    Writeln('Введите номер дня недели(число от 1 до 7)');
    Repeat
        IsCorrect := True;
        try
            Readln(Number);
        except
            Writeln('Ошибка. Проверьте корректность введенных данных');
            IsCorrect := False;
        end;
        if (IsCorrect) and (Number < 1) or (Number > 7) then
        begin
            Writeln('Ошибка. Введите число от 1 до 7!');
            IsCorrect := False;
        end;
    Until (IsCorrect);
    case Number of
        1: Writeln('Понедельник');
        2: Writeln('Вторник');
        3: Writeln('Среда');
        4: Writeln('Четверг');
        5: Writeln('Пятница');
        6: Writeln('Суббота');
        7: Writeln('Воскресенье');
    end;
    Readln;
end.
