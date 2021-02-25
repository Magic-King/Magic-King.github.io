#include <idc.idc>

/*
//part1:helloworld
static main(){
	//Wait();
	Message("Hello world");
	//Exit(0);
	return 0;
}
*/

//part2:see segment

static list_segs()
{	auto ea, i=0;
	ea = FirstSeg();
	while (ea != BADADDR)
	{	Message("\nsegment %d 0x%08X-0x%08X\n", 
 			i, ea, SegEnd(ea));
		//list_func_with_ref(ea);
		ea = NextSeg(ea);
		i++;
}	
}

static main()
{		//Wait();
		list_segs();
		//func_list_ref();		
		Message("\n\n bye \n\n");		
		//Exit(0);
}



//part3:see function

static list_func_with_ref(ea)
{
    auto func;
    func = SegStart(ea);
    //Message("first addr is %x\n", func); // note: first address maybe not a func
    while (func != BADADDR && func < SegEnd(ea))
    {
        if (GetFunctionFlags(func) != -1) // if really a func
        {
            auto ref, tip;
            if (func>=SegStart(ea) && func<SegEnd(ea))
                tip = "Internal";
            else
                tip = "External";
            Message("%s Function 0x%08X %s\n", tip, func, GetFunctionName(func));
            for (ref=RfirstB(func); ref != BADADDR; ref=RnextB(func, ref))
            {
                auto caller_name, caller_addr;
                caller_name = GetFunctionName(ref);
                caller_addr = GetFunctionAttr(ref, FUNCATTR_START);
                Message("  called at 0x%08X by 0x%08X(%s)\n", ref, caller_addr, caller_name);
            }
        }
        func=NextFunction(func);
    }
}

static main()
{		
		Message("Hello!");
		//Wait();
		//list_segs();
		auto ea;
		ea = FirstSeg();
		list_func_with_ref(ea);		
		Message("\n\n bye \n\n");		
		//Exit(0);
}


