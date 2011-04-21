// ALi by NewX

#include <localtime.h>

static string *c_digit = ({ "��","ʮ","��","ǧ","��","��","��" });
static string *c_num = ({"��","һ","��","��","��","��","��","��","��","��","ʮ"});
static string *sym_tien = ({ "��","��","��","��","��","��","��","��","��","��" });
static string *sym_dee = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });

string chinese_number(int i)
{
    if (i<0) return "��" + chinese_number(-i);
    if (i<11) return c_num[i];
    if (i<20) return c_num[10] + c_num[i-10];
    if (i<100) {
        if (i%10) return c_num[i/10] + c_digit[1] + c_num[i%10];
        else return c_num[i/10] + c_digit[1];
    }
    if (i<1000) {
        if (i%100==0)
            return c_num[i/100] + c_digit[2];
        else if (i%100<10)
            return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i%100);
        else if (i%100<20)
            return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i%100);
        else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
    }
    if (i<10000) {
        if (i%1000==0)
            return c_num[i/1000] + c_digit[3];
        else if(i%1000<100)
            return c_num[i/1000] + c_digit[3] + c_digit[0] + chinese_number(i%1000);
        else
            return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
    }
    if (i<100000000) {
        if (i%10000==0)
            return chinese_number(i/10000) + c_digit[4];
        else if (i%10000<1000)
            return chinese_number(i/10000) + c_digit[4] + c_digit[0] + chinese_number(i%10000);
        else
            return chinese_number(i/10000) + c_digit[4] + chinese_number(i%10000);
    }
    if (i<1000000000000) {
        if (i%100000000==0)
            return chinese_number(i/100000000) + c_digit[5];
        else if (i%100000000<10000000)
            return chinese_number(i/100000000) + c_digit[5] + c_digit[0] + chinese_number(i%100000000);
        else
            return chinese_number(i/100000000) + c_digit[5] + chinese_number(i%100000000);
    }
        if (i%1000000000000==0)
            return chinese_number(i/1000000000000) + c_digit[6];
        else if (i%1000000000000<100000000000)
            return chinese_number(i/1000000000000) + c_digit[6] + c_digit[0] + chinese_number(i%1000000000000);
        else
            return chinese_number(i/1000000000000) + c_digit[6] + chinese_number(i%1000000000000);
}

string chinese_date(int date)
{
    mixed *local;
    local = localtime(date);
    return sprintf("%s%s��%s��%s��%sʱ%s��",
        sym_tien[(local[LT_YEAR]+6)%10], sym_dee[(local[LT_YEAR]+10)%12],
        chinese_number(local[LT_MON]+1),
        chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
        sym_dee[(local[LT_HOUR]%24)/2],
        chinese_number(local[LT_HOUR]%2 * 2 + local[LT_MIN]/30 + 1));
}
