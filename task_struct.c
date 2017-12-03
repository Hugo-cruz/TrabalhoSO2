struct task_struct {
   #ifdef CONFIG_THREAD_INFO_IN_TASK
       /*
        * For reasons of header soup (see current_thread_info()), this
        * must be the first element of task_struct.
        */
       struct thread_info      thread_info;
   #endif
       /* -1 unrunnable, 0 runnable, >0 stopped: */
       volatile long           state;
       void                    *stack;
       /* Per task flags (PF_*), defined further below: */
       unsigned int            flags;
       unsigned int            ptrace;
       /* Current CPU: */
       unsigned int            cpu;
       int                     on_cpu;
   
       int                     on_rq;
   
       int                     prio;
       int                     static_prio;
       int                     normal_prio;
       unsigned int            rt_priority;
   
       const struct sched_class    *sched_class;
   
       unsigned int            policy;
       int                     nr_cpus_allowed;
       cpumask_t               cpus_allowed;
   
       struct list_head        tasks;
   
       struct mm_struct        *mm;
       struct mm_struct        *active_mm;
   
       int                     exit_state;
       int                     exit_code;
       int                     exit_signal;
       /* The signal sent when the parent dies: */
       int                     pdeath_signal;
   
       pid_t                   pid;
       pid_t                   tgid;
   
       /* Canary value for the -fstack-protector GCC feature: */
       unsigned long           stack_canary;
   
       /* Real parent process: */
       struct task_struct __rcu    *real_parent;
   
       /* Recipient of SIGCHLD, wait4() reports: */
       struct task_struct __rcu    *parent;
   
       /* Children/sibling form the list of natural children: */
       struct list_head        children;
       struct list_head        sibling;
       struct task_struct      *group_leader;

struct completion       *vfork_done;
   
       /* CLONE_CHILD_SETTID: */
       int __user              *set_child_tid;
   
       /* CLONE_CHILD_CLEARTID: */
       int __user              *clear_child_tid;
   
       u64                     utime;
       u64                     stime;
       u64                     utimescaled;
       u64                     stimescaled;
       u64                     gtime;
       struct prev_cputime     prev_cputime;
   
       /* Monotonic time in nsecs: */
       u64                     start_time;
   
       /* Boot based time in nsecs: */
       u64                     real_start_time;
   
       /* Objective and real subjective task credentials (COW): */
       const struct cred __rcu     *real_cred;
   
       /* Effective (overridable) subjective task credentials (COW): */
       const struct cred __rcu     *cred;
   
   #ifdef CONFIG_SYSVIPC
       struct sysv_sem         sysvsem;
       struct sysv_shm         sysvshm;
   #endif
   
       /* Filesystem information: */
       struct fs_struct        *fs;
   
       /* Open file information: */
       struct files_struct     *files;
   
       /* Namespaces: */
       struct nsproxy          *nsproxy;
   
       /* Signal handlers: */
       struct signal_struct    *signal;
       struct sighand_struct   *sighand;
       sigset_t                blocked;
       sigset_t                real_blocked;
       /* Restored if set_restore_sigmask() was used: */
       sigset_t                saved_sigmask;
       struct sigpending       pending;
   
       /* Thread group tracking: */
       u32                     parent_exec_id;
       u32                     self_exec_id;
       
       /* Journalling filesystem info: */
       void                    *journal_info;
   
       /* Index of current stored address in ret_stack: */
       int                     curr_ret_stack;
   
       /* CPU-specific state of this task: */
       struct thread_struct    thread;
   
       /*
        * WARNING: on x86, 'thread_struct' contains a variable-sized
        * structure.  It *MUST* be at the end of 'task_struct'.
        *
        * Do not put anything below here!
        */
   };