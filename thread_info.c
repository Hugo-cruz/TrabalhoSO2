   /*
    * On IA-64, we want to keep the task structure and kernel stack together, so they can be
    * mapped by a single TLB entry and so they can be addressed by the "current" pointer
    * without having to do pointer masking.
    */
   struct thread_info {
       struct task_struct *task;   /* XXX not really needed, except for dup_task_struct() */
       __u32 flags;                /* thread_info flags (see TIF_*) */
       __u32 cpu;                  /* current CPU */
       __u32 last_cpu;             /* Last CPU thread ran on */
       __u32 status;               /* Thread synchronous flags */
       mm_segment_t addr_limit;    /* user-level address space limit */
       int preempt_count;          /* 0=premptable, <0=BUG; will also serve as bh-counter */
   #ifdef CONFIG_VIRT_CPU_ACCOUNTING_NATIVE
       __u64 utime;
       __u64 stime;
       __u64 gtime;
       __u64 hardirq_time;
       __u64 softirq_time;
       __u64 idle_time;
       __u64 ac_stamp;
       __u64 ac_leave;
       __u64 ac_stime;
       __u64 ac_utime;
   #endif
   };