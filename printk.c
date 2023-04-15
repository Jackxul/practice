//kernel
#include <linux/kernel.h>
int printk(const char *fmt, ...)
{
    va_list args;
    int r;
    va_start(args, fmt);
    r = vprintk(fmt, args);
    va_end(args);
    return r;
}
