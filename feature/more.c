// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// more.c

#include <ansi.h>

varargs void more(string cmd, string *text, int line, int force)
{
    int i,j;

    switch(cmd) {
        case "b":
            line = line - 46;
            if (line <- 22 && !force) return;
                write("\n"+ESC+"[1A"+ESC+"[100D"+ESC+"[K\n"+repeat_string("-",100)+"\n");
            for (i = line + 23; line < i; line++)
                write(text[line] + "\n");
            break;
        case "q":
            write(ESC+"[1A"+ESC+"[100D"+ESC+"[K\n");
            return;
        case "":
        case "f":
        default:
            write(ESC+"[1A"+ESC+"[100D"+ESC+"[K");
            for(i = line + 23; line < sizeof(text) && line < i; line++)
                write(text[line] + "\n");
            if (line >= sizeof(text) && !force) return;
            break;
    }
    printf("== δ����� " HIY "%d%%" NOR " == ("HIG"q"NOR" �뿪��"HIG"b"NOR" ǰһҳ��"HIG"[������]"NOR" ������һҳ)",
        (line*100/sizeof(text)));
    input_to("more", text, line);
}

varargs void start_more(string msg, int force)
{
    if (!msg || strlen(msg) < 1) // no messages.
        return;
    //11/13/97 try to prevent crash by mon.

    write("\n");
    more("", explode(msg, "\n"), 0, force);
}
