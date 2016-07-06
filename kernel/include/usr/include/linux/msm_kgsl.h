#ifndef _MSM_KGSL_H
#define _MSM_KGSL_H


#define KGSL_VERSION_MAJOR        3
#define KGSL_VERSION_MINOR        14


#define KGSL_CONTEXT_SAVE_GMEM		0x00000001
#define KGSL_CONTEXT_NO_GMEM_ALLOC	0x00000002
#define KGSL_CONTEXT_SUBMIT_IB_LIST	0x00000004
#define KGSL_CONTEXT_CTX_SWITCH		0x00000008
#define KGSL_CONTEXT_PREAMBLE		0x00000010
#define KGSL_CONTEXT_TRASH_STATE	0x00000020
#define KGSL_CONTEXT_PER_CONTEXT_TS	0x00000040
#define KGSL_CONTEXT_USER_GENERATED_TS	0x00000080
#define KGSL_CONTEXT_END_OF_FRAME	0x00000100
#define KGSL_CONTEXT_NO_FAULT_TOLERANCE 0x00000200
#define KGSL_CONTEXT_SYNC               0x00000400
#define KGSL_CONTEXT_PWR_CONSTRAINT     0x00000800

#define KGSL_CONTEXT_PRIORITY_MASK      0x0000F000
#define KGSL_CONTEXT_PRIORITY_SHIFT     12
#define KGSL_CONTEXT_PRIORITY_UNDEF     0

#define KGSL_CONTEXT_IFH_NOP            0x00010000
#define KGSL_CONTEXT_SECURE             0x00020000

#define KGSL_CONTEXT_TYPE_MASK          0x01F00000
#define KGSL_CONTEXT_TYPE_SHIFT         20
#define KGSL_CONTEXT_TYPE_ANY		0
#define KGSL_CONTEXT_TYPE_GL		1
#define KGSL_CONTEXT_TYPE_CL		2
#define KGSL_CONTEXT_TYPE_C2D		3
#define KGSL_CONTEXT_TYPE_RS		4
#define KGSL_CONTEXT_TYPE_UNKNOWN	0x1E

#define KGSL_CONTEXT_INVALID 0xffffffff

#define KGSL_CMDBATCH_MEMLIST		0x00000001
#define KGSL_CMDBATCH_MARKER		0x00000002
#define KGSL_CMDBATCH_SUBMIT_IB_LIST	KGSL_CONTEXT_SUBMIT_IB_LIST 
#define KGSL_CMDBATCH_CTX_SWITCH	KGSL_CONTEXT_CTX_SWITCH     
#define KGSL_CMDBATCH_PROFILING		0x00000010
#define KGSL_CMDBATCH_END_OF_FRAME	KGSL_CONTEXT_END_OF_FRAME   
#define KGSL_CMDBATCH_SYNC		KGSL_CONTEXT_SYNC           
#define KGSL_CMDBATCH_PWR_CONSTRAINT	KGSL_CONTEXT_PWR_CONSTRAINT 



#define KGSL_MEMFLAGS_GPUREADONLY 0x01000000
#define KGSL_MEMFLAGS_USE_CPU_MAP 0x10000000

#define KGSL_MEMFLAGS_SECURE      0x00000008

#define KGSL_CACHEMODE_MASK 0x0C000000
#define KGSL_CACHEMODE_SHIFT 26

#define KGSL_CACHEMODE_WRITECOMBINE 0
#define KGSL_CACHEMODE_UNCACHED 1
#define KGSL_CACHEMODE_WRITETHROUGH 2
#define KGSL_CACHEMODE_WRITEBACK 3

#define KGSL_MEMTYPE_MASK		0x0000FF00
#define KGSL_MEMTYPE_SHIFT		8

#define KGSL_MEMTYPE_OBJECTANY			0
#define KGSL_MEMTYPE_FRAMEBUFFER		1
#define KGSL_MEMTYPE_RENDERBUFFER		2
#define KGSL_MEMTYPE_ARRAYBUFFER		3
#define KGSL_MEMTYPE_ELEMENTARRAYBUFFER		4
#define KGSL_MEMTYPE_VERTEXARRAYBUFFER		5
#define KGSL_MEMTYPE_TEXTURE			6
#define KGSL_MEMTYPE_SURFACE			7
#define KGSL_MEMTYPE_EGL_SURFACE		8
#define KGSL_MEMTYPE_GL				9
#define KGSL_MEMTYPE_CL				10
#define KGSL_MEMTYPE_CL_BUFFER_MAP		11
#define KGSL_MEMTYPE_CL_BUFFER_NOMAP		12
#define KGSL_MEMTYPE_CL_IMAGE_MAP		13
#define KGSL_MEMTYPE_CL_IMAGE_NOMAP		14
#define KGSL_MEMTYPE_CL_KERNEL_STACK		15
#define KGSL_MEMTYPE_COMMAND			16
#define KGSL_MEMTYPE_2D				17
#define KGSL_MEMTYPE_EGL_IMAGE			18
#define KGSL_MEMTYPE_EGL_SHADOW			19
#define KGSL_MEMTYPE_MULTISAMPLE		20
#define KGSL_MEMTYPE_KERNEL			255

#define KGSL_MEMALIGN_MASK		0x00FF0000
#define KGSL_MEMALIGN_SHIFT		16

enum kgsl_user_mem_type {
	KGSL_USER_MEM_TYPE_PMEM		= 0x00000000,
	KGSL_USER_MEM_TYPE_ASHMEM	= 0x00000001,
	KGSL_USER_MEM_TYPE_ADDR		= 0x00000002,
	KGSL_USER_MEM_TYPE_ION		= 0x00000003,
	KGSL_USER_MEM_TYPE_MAX		= 0x00000007,
};
#define KGSL_MEMFLAGS_USERMEM_MASK 0x000000e0
#define KGSL_MEMFLAGS_USERMEM_SHIFT 5

#define KGSL_USERMEM_FLAG(x) (((x) + 1) << KGSL_MEMFLAGS_USERMEM_SHIFT)

#define KGSL_MEMFLAGS_NOT_USERMEM 0
#define KGSL_MEMFLAGS_USERMEM_PMEM KGSL_USERMEM_FLAG(KGSL_USER_MEM_TYPE_PMEM)
#define KGSL_MEMFLAGS_USERMEM_ASHMEM \
		KGSL_USERMEM_FLAG(KGSL_USER_MEM_TYPE_ASHMEM)
#define KGSL_MEMFLAGS_USERMEM_ADDR KGSL_USERMEM_FLAG(KGSL_USER_MEM_TYPE_ADDR)
#define KGSL_MEMFLAGS_USERMEM_ION KGSL_USERMEM_FLAG(KGSL_USER_MEM_TYPE_ION)


#define KGSL_FLAGS_NORMALMODE  0x00000000
#define KGSL_FLAGS_SAFEMODE    0x00000001
#define KGSL_FLAGS_INITIALIZED0 0x00000002
#define KGSL_FLAGS_INITIALIZED 0x00000004
#define KGSL_FLAGS_STARTED     0x00000008
#define KGSL_FLAGS_ACTIVE      0x00000010
#define KGSL_FLAGS_RESERVED0   0x00000020
#define KGSL_FLAGS_RESERVED1   0x00000040
#define KGSL_FLAGS_RESERVED2   0x00000080
#define KGSL_FLAGS_SOFT_RESET  0x00000100
#define KGSL_FLAGS_PER_CONTEXT_TIMESTAMPS 0x00000200

#define KGSL_CLK_SRC	0x00000001
#define KGSL_CLK_CORE	0x00000002
#define KGSL_CLK_IFACE	0x00000004
#define KGSL_CLK_MEM	0x00000008
#define KGSL_CLK_MEM_IFACE 0x00000010
#define KGSL_CLK_AXI	0x00000020

#define KGSL_SYNCOBJ_SERVER_TIMEOUT 2000

enum kgsl_ctx_reset_stat {
	KGSL_CTX_STAT_NO_ERROR				= 0x00000000,
	KGSL_CTX_STAT_GUILTY_CONTEXT_RESET_EXT		= 0x00000001,
	KGSL_CTX_STAT_INNOCENT_CONTEXT_RESET_EXT	= 0x00000002,
	KGSL_CTX_STAT_UNKNOWN_CONTEXT_RESET_EXT		= 0x00000003
};

#define KGSL_CONVERT_TO_MBPS(val) \
	(val*1000*1000U)

enum kgsl_deviceid {
	KGSL_DEVICE_3D0		= 0x00000000,
	KGSL_DEVICE_2D0		= 0x00000001,
	KGSL_DEVICE_2D1		= 0x00000002,
	KGSL_DEVICE_MAX		= 0x00000003
};

struct kgsl_devinfo {

	unsigned int device_id;
	unsigned int chip_id;
	unsigned int mmu_enabled;
	unsigned long gmem_gpubaseaddr;
	unsigned int gpu_id;
	size_t gmem_sizebytes;
};

/* this structure defines the region of memory that can be mmap()ed from this
   driver. The timestamp fields are __volatile__ because they are written by the
   GPU
*/
struct kgsl_devmemstore {
	__volatile__ unsigned int soptimestamp;
	unsigned int sbz;
	__volatile__ unsigned int eoptimestamp;
	unsigned int sbz2;
	__volatile__ unsigned int ts_cmp_enable;
	unsigned int sbz3;
	__volatile__ unsigned int ref_wait_ts;
	unsigned int sbz4;
	unsigned int current_context;
	unsigned int sbz5;
};

#define KGSL_MEMSTORE_OFFSET(ctxt_id, field) \
	((ctxt_id)*sizeof(struct kgsl_devmemstore) + \
	 offsetof(struct kgsl_devmemstore, field))

enum kgsl_timestamp_type {
	KGSL_TIMESTAMP_CONSUMED = 0x00000001, 
	KGSL_TIMESTAMP_RETIRED  = 0x00000002, 
	KGSL_TIMESTAMP_QUEUED   = 0x00000003,
};

enum kgsl_property_type {
	KGSL_PROP_DEVICE_INFO     = 0x00000001,
	KGSL_PROP_DEVICE_SHADOW   = 0x00000002,
	KGSL_PROP_DEVICE_POWER    = 0x00000003,
	KGSL_PROP_SHMEM           = 0x00000004,
	KGSL_PROP_SHMEM_APERTURES = 0x00000005,
	KGSL_PROP_MMU_ENABLE 	  = 0x00000006,
	KGSL_PROP_INTERRUPT_WAITS = 0x00000007,
	KGSL_PROP_VERSION         = 0x00000008,
	KGSL_PROP_GPU_RESET_STAT  = 0x00000009,
	KGSL_PROP_PWRCTRL         = 0x0000000E,
	KGSL_PROP_PWR_CONSTRAINT  = 0x00000012,
};

struct kgsl_shadowprop {
	unsigned long gpuaddr;
	size_t size;
	unsigned int flags; 
};

struct kgsl_version {
	unsigned int drv_major;
	unsigned int drv_minor;
	unsigned int dev_major;
	unsigned int dev_minor;
};


#define KGSL_PERFCOUNTER_GROUP_CP 0x0
#define KGSL_PERFCOUNTER_GROUP_RBBM 0x1
#define KGSL_PERFCOUNTER_GROUP_PC 0x2
#define KGSL_PERFCOUNTER_GROUP_VFD 0x3
#define KGSL_PERFCOUNTER_GROUP_HLSQ 0x4
#define KGSL_PERFCOUNTER_GROUP_VPC 0x5
#define KGSL_PERFCOUNTER_GROUP_TSE 0x6
#define KGSL_PERFCOUNTER_GROUP_RAS 0x7
#define KGSL_PERFCOUNTER_GROUP_UCHE 0x8
#define KGSL_PERFCOUNTER_GROUP_TP 0x9
#define KGSL_PERFCOUNTER_GROUP_SP 0xA
#define KGSL_PERFCOUNTER_GROUP_RB 0xB
#define KGSL_PERFCOUNTER_GROUP_PWR 0xC
#define KGSL_PERFCOUNTER_GROUP_VBIF 0xD
#define KGSL_PERFCOUNTER_GROUP_VBIF_PWR 0xE
#define KGSL_PERFCOUNTER_GROUP_MH 0xF
#define KGSL_PERFCOUNTER_GROUP_PA_SU 0x10
#define KGSL_PERFCOUNTER_GROUP_SQ 0x11
#define KGSL_PERFCOUNTER_GROUP_SX 0x12
#define KGSL_PERFCOUNTER_GROUP_TCF 0x13
#define KGSL_PERFCOUNTER_GROUP_TCM 0x14
#define KGSL_PERFCOUNTER_GROUP_TCR 0x15
#define KGSL_PERFCOUNTER_GROUP_L2 0x16
#define KGSL_PERFCOUNTER_GROUP_VSC 0x17
#define KGSL_PERFCOUNTER_GROUP_CCU 0x18
#define KGSL_PERFCOUNTER_GROUP_ALWAYSON 0x1B
#define KGSL_PERFCOUNTER_GROUP_MAX 0x1C

#define KGSL_PERFCOUNTER_NOT_USED 0xFFFFFFFF
#define KGSL_PERFCOUNTER_BROKEN 0xFFFFFFFE

struct kgsl_ibdesc {
	unsigned long gpuaddr;
	unsigned long __pad;
	size_t sizedwords;
	unsigned int ctrl;
};

struct kgsl_cmdbatch_profiling_buffer {
	uint64_t wall_clock_s;
	uint64_t wall_clock_ns;
	uint64_t gpu_ticks_queued;
	uint64_t gpu_ticks_submitted;
	uint64_t gpu_ticks_retired;
};

#define KGSL_IOC_TYPE 0x09

struct kgsl_device_getproperty {
	unsigned int type;
	void *value;
	size_t sizebytes;
};

#define IOCTL_KGSL_DEVICE_GETPROPERTY \
	_IOWR(KGSL_IOC_TYPE, 0x2, struct kgsl_device_getproperty)


struct kgsl_device_waittimestamp {
	unsigned int timestamp;
	unsigned int timeout;
};

#define IOCTL_KGSL_DEVICE_WAITTIMESTAMP \
	_IOW(KGSL_IOC_TYPE, 0x6, struct kgsl_device_waittimestamp)

struct kgsl_device_waittimestamp_ctxtid {
	unsigned int context_id;
	unsigned int timestamp;
	unsigned int timeout;
};

#define IOCTL_KGSL_DEVICE_WAITTIMESTAMP_CTXTID \
	_IOW(KGSL_IOC_TYPE, 0x7, struct kgsl_device_waittimestamp_ctxtid)

struct kgsl_ringbuffer_issueibcmds {
	unsigned int drawctxt_id;
	unsigned long ibdesc_addr;
	unsigned int numibs;
	unsigned int timestamp; 
	unsigned int flags;
};

#define IOCTL_KGSL_RINGBUFFER_ISSUEIBCMDS \
	_IOWR(KGSL_IOC_TYPE, 0x10, struct kgsl_ringbuffer_issueibcmds)

struct kgsl_cmdstream_readtimestamp {
	unsigned int type;
	unsigned int timestamp; 
};

#define IOCTL_KGSL_CMDSTREAM_READTIMESTAMP_OLD \
	_IOR(KGSL_IOC_TYPE, 0x11, struct kgsl_cmdstream_readtimestamp)

#define IOCTL_KGSL_CMDSTREAM_READTIMESTAMP \
	_IOWR(KGSL_IOC_TYPE, 0x11, struct kgsl_cmdstream_readtimestamp)

struct kgsl_cmdstream_freememontimestamp {
	unsigned long gpuaddr;
	unsigned int type;
	unsigned int timestamp;
};

#define IOCTL_KGSL_CMDSTREAM_FREEMEMONTIMESTAMP \
	_IOW(KGSL_IOC_TYPE, 0x12, struct kgsl_cmdstream_freememontimestamp)


#define IOCTL_KGSL_CMDSTREAM_FREEMEMONTIMESTAMP_OLD \
	_IOR(KGSL_IOC_TYPE, 0x12, struct kgsl_cmdstream_freememontimestamp)

struct kgsl_drawctxt_create {
	unsigned int flags;
	unsigned int drawctxt_id; 
};

#define IOCTL_KGSL_DRAWCTXT_CREATE \
	_IOWR(KGSL_IOC_TYPE, 0x13, struct kgsl_drawctxt_create)

struct kgsl_drawctxt_destroy {
	unsigned int drawctxt_id;
};

#define IOCTL_KGSL_DRAWCTXT_DESTROY \
	_IOW(KGSL_IOC_TYPE, 0x14, struct kgsl_drawctxt_destroy)

struct kgsl_map_user_mem {
	int fd;
	unsigned long gpuaddr;   
	size_t len;
	size_t offset;
	unsigned long hostptr;   
	enum kgsl_user_mem_type memtype;
	unsigned int flags;
};

#define IOCTL_KGSL_MAP_USER_MEM \
	_IOWR(KGSL_IOC_TYPE, 0x15, struct kgsl_map_user_mem)

struct kgsl_cmdstream_readtimestamp_ctxtid {
	unsigned int context_id;
	unsigned int type;
	unsigned int timestamp; 
};

#define IOCTL_KGSL_CMDSTREAM_READTIMESTAMP_CTXTID \
	_IOWR(KGSL_IOC_TYPE, 0x16, struct kgsl_cmdstream_readtimestamp_ctxtid)

struct kgsl_cmdstream_freememontimestamp_ctxtid {
	unsigned int context_id;
	unsigned long gpuaddr;
	unsigned int type;
	unsigned int timestamp;
};

#define IOCTL_KGSL_CMDSTREAM_FREEMEMONTIMESTAMP_CTXTID \
	_IOW(KGSL_IOC_TYPE, 0x17, \
	struct kgsl_cmdstream_freememontimestamp_ctxtid)

struct kgsl_sharedmem_from_pmem {
	int pmem_fd;
	unsigned long gpuaddr;	
	unsigned int len;
	unsigned int offset;
};

#define IOCTL_KGSL_SHAREDMEM_FROM_PMEM \
	_IOWR(KGSL_IOC_TYPE, 0x20, struct kgsl_sharedmem_from_pmem)

struct kgsl_sharedmem_free {
	unsigned long gpuaddr;
};

#define IOCTL_KGSL_SHAREDMEM_FREE \
	_IOW(KGSL_IOC_TYPE, 0x21, struct kgsl_sharedmem_free)

struct kgsl_cff_user_event {
	unsigned char cff_opcode;
	unsigned int op1;
	unsigned int op2;
	unsigned int op3;
	unsigned int op4;
	unsigned int op5;
	unsigned int __pad[2];
};

#define IOCTL_KGSL_CFF_USER_EVENT \
	_IOW(KGSL_IOC_TYPE, 0x31, struct kgsl_cff_user_event)

struct kgsl_gmem_desc {
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
	unsigned int pitch;
};

struct kgsl_buffer_desc {
	void 			*hostptr;
	unsigned long	gpuaddr;
	int				size;
	unsigned int	format;
	unsigned int  	pitch;
	unsigned int  	enabled;
};

struct kgsl_bind_gmem_shadow {
	unsigned int drawctxt_id;
	struct kgsl_gmem_desc gmem_desc;
	unsigned int shadow_x;
	unsigned int shadow_y;
	struct kgsl_buffer_desc shadow_buffer;
	unsigned int buffer_id;
};

#define IOCTL_KGSL_DRAWCTXT_BIND_GMEM_SHADOW \
    _IOW(KGSL_IOC_TYPE, 0x22, struct kgsl_bind_gmem_shadow)



struct kgsl_sharedmem_from_vmalloc {
	unsigned long gpuaddr;	
	unsigned int hostptr;
	unsigned int flags;
};

#define IOCTL_KGSL_SHAREDMEM_FROM_VMALLOC \
	_IOWR(KGSL_IOC_TYPE, 0x23, struct kgsl_sharedmem_from_vmalloc)


#define IOCTL_KGSL_SHAREDMEM_FLUSH_CACHE \
	_IOW(KGSL_IOC_TYPE, 0x24, struct kgsl_sharedmem_free)

struct kgsl_drawctxt_set_bin_base_offset {
	unsigned int drawctxt_id;
	unsigned int offset;
};

#define IOCTL_KGSL_DRAWCTXT_SET_BIN_BASE_OFFSET \
	_IOW(KGSL_IOC_TYPE, 0x25, struct kgsl_drawctxt_set_bin_base_offset)

enum kgsl_cmdwindow_type {
	KGSL_CMDWINDOW_MIN     = 0x00000000,
	KGSL_CMDWINDOW_2D      = 0x00000000,
	KGSL_CMDWINDOW_3D      = 0x00000001, 
	KGSL_CMDWINDOW_MMU     = 0x00000002,
	KGSL_CMDWINDOW_ARBITER = 0x000000FF,
	KGSL_CMDWINDOW_MAX     = 0x000000FF,
};

struct kgsl_cmdwindow_write {
	enum kgsl_cmdwindow_type target;
	unsigned int addr;
	unsigned int data;
};

#define IOCTL_KGSL_CMDWINDOW_WRITE \
	_IOW(KGSL_IOC_TYPE, 0x2e, struct kgsl_cmdwindow_write)

struct kgsl_gpumem_alloc {
	unsigned long gpuaddr; 
	size_t size;
	unsigned int flags;
};

#define IOCTL_KGSL_GPUMEM_ALLOC \
	_IOWR(KGSL_IOC_TYPE, 0x2f, struct kgsl_gpumem_alloc)

struct kgsl_cff_syncmem {
	unsigned long gpuaddr;
	size_t len;
	unsigned int __pad[2]; 
};

#define IOCTL_KGSL_CFF_SYNCMEM \
	_IOW(KGSL_IOC_TYPE, 0x30, struct kgsl_cff_syncmem)


struct kgsl_timestamp_event {
	int type;                
	unsigned int timestamp;  
	unsigned int context_id; 
	void *priv;	 
	size_t len;              
};

#define IOCTL_KGSL_TIMESTAMP_EVENT_OLD \
	_IOW(KGSL_IOC_TYPE, 0x31, struct kgsl_timestamp_event)


#define KGSL_TIMESTAMP_EVENT_GENLOCK 1

struct kgsl_timestamp_event_genlock {
	int handle; 
};


#define KGSL_TIMESTAMP_EVENT_FENCE 2

struct kgsl_timestamp_event_fence {
	int fence_fd; 
};


#define IOCTL_KGSL_SETPROPERTY \
	_IOW(KGSL_IOC_TYPE, 0x32, struct kgsl_device_getproperty)

#define IOCTL_KGSL_TIMESTAMP_EVENT \
	_IOWR(KGSL_IOC_TYPE, 0x33, struct kgsl_timestamp_event)

struct kgsl_gpumem_alloc_id {
	unsigned int id;
	unsigned int flags;
	size_t size;
	size_t mmapsize;
	unsigned long gpuaddr;
	unsigned long __pad[2];
};

#define IOCTL_KGSL_GPUMEM_ALLOC_ID \
	_IOWR(KGSL_IOC_TYPE, 0x34, struct kgsl_gpumem_alloc_id)

struct kgsl_gpumem_free_id {
	unsigned int id;
	unsigned int __pad;
};

#define IOCTL_KGSL_GPUMEM_FREE_ID \
	_IOWR(KGSL_IOC_TYPE, 0x35, struct kgsl_gpumem_free_id)

struct kgsl_gpumem_get_info {
	unsigned long gpuaddr;
	unsigned int id;
	unsigned int flags;
	size_t size;
	size_t mmapsize;
	unsigned long useraddr;
	unsigned long __pad[4];
};

#define IOCTL_KGSL_GPUMEM_GET_INFO\
	_IOWR(KGSL_IOC_TYPE, 0x36, struct kgsl_gpumem_get_info)

struct kgsl_gpumem_sync_cache {
	unsigned long gpuaddr;
	unsigned int id;
	unsigned int op;
	size_t offset;
	size_t length;
};

#define KGSL_GPUMEM_CACHE_CLEAN (1 << 0)
#define KGSL_GPUMEM_CACHE_TO_GPU KGSL_GPUMEM_CACHE_CLEAN

#define KGSL_GPUMEM_CACHE_INV (1 << 1)
#define KGSL_GPUMEM_CACHE_FROM_GPU KGSL_GPUMEM_CACHE_INV

#define KGSL_GPUMEM_CACHE_FLUSH \
	(KGSL_GPUMEM_CACHE_CLEAN | KGSL_GPUMEM_CACHE_INV)

#define KGSL_GPUMEM_CACHE_RANGE (1 << 31U)

#define IOCTL_KGSL_GPUMEM_SYNC_CACHE \
	_IOW(KGSL_IOC_TYPE, 0x37, struct kgsl_gpumem_sync_cache)

struct kgsl_perfcounter_get {
	unsigned int groupid;
	unsigned int countable;
	unsigned int offset;
	unsigned int offset_hi;
	unsigned int __pad; 
};

#define IOCTL_KGSL_PERFCOUNTER_GET \
	_IOWR(KGSL_IOC_TYPE, 0x38, struct kgsl_perfcounter_get)

struct kgsl_perfcounter_put {
	unsigned int groupid;
	unsigned int countable;
	unsigned int __pad[2]; 
};

#define IOCTL_KGSL_PERFCOUNTER_PUT \
	_IOW(KGSL_IOC_TYPE, 0x39, struct kgsl_perfcounter_put)

/**
 * struct kgsl_perfcounter_query - argument to IOCTL_KGSL_PERFCOUNTER_QUERY
 * @groupid: Performance counter group ID
 * @countable: Return active countables array
 * @size: Size of active countables array
 * @max_counters: Return total number counters for the group ID
 *
 * Query the available performance counters given a groupid.  The array
 * *countables is used to return the current active countables in counters.
 * The size of the array is passed in so the kernel will only write at most
 * size or counter->size for the group id.  The total number of available
 * counters for the group ID is returned in max_counters.
 * If the array or size passed in are invalid, then only the maximum number
 * of counters will be returned, no data will be written to *countables.
 * If the groupid is invalid an error code will be returned.
 *
 */
struct kgsl_perfcounter_query {
	unsigned int groupid;
	
	unsigned int *countables;
	unsigned int count;
	unsigned int max_counters;
	unsigned int __pad[2]; 
};

#define IOCTL_KGSL_PERFCOUNTER_QUERY \
	_IOWR(KGSL_IOC_TYPE, 0x3A, struct kgsl_perfcounter_query)


struct kgsl_perfcounter_read_group {
	unsigned int groupid;
	unsigned int countable;
	unsigned long long value;
};

struct kgsl_perfcounter_read {
	struct kgsl_perfcounter_read_group *reads;
	unsigned int count;
	unsigned int __pad[2]; 
};

#define IOCTL_KGSL_PERFCOUNTER_READ \
	_IOWR(KGSL_IOC_TYPE, 0x3B, struct kgsl_perfcounter_read)
struct kgsl_gpumem_sync_cache_bulk {
	unsigned int *id_list;
	unsigned int count;
	unsigned int op;
	unsigned int __pad[2]; 
};

#define IOCTL_KGSL_GPUMEM_SYNC_CACHE_BULK \
	_IOWR(KGSL_IOC_TYPE, 0x3C, struct kgsl_gpumem_sync_cache_bulk)

#ifdef CONFIG_MSM_KGSL
unsigned int kgsl_get_alloc_size(int detailed);
#else
static __inline__ unsigned int kgsl_get_alloc_size(int detailed)
{
        return 0;
}
#endif

struct kgsl_cmd_syncpoint_timestamp {
	unsigned int context_id;
	unsigned int timestamp;
};

#define KGSL_CMD_SYNCPOINT_TYPE_TIMESTAMP 0

struct kgsl_cmd_syncpoint_fence {
	int fd;
};

#define KGSL_CMD_SYNCPOINT_TYPE_FENCE 1

struct kgsl_cmd_syncpoint {
	int type;
	void *priv;
	size_t size;
};

#define KGSL_IBDESC_MEMLIST 0x1

#define KGSL_IBDESC_PROFILING_BUFFER 0x2


struct kgsl_submit_commands {
	unsigned int context_id;
	unsigned int flags;
	struct kgsl_ibdesc *cmdlist;
	unsigned int numcmds;
	struct kgsl_cmd_syncpoint *synclist;
	unsigned int numsyncs;
	unsigned int timestamp;
	unsigned int __pad[4];
};

#define IOCTL_KGSL_SUBMIT_COMMANDS \
	_IOWR(KGSL_IOC_TYPE, 0x3D, struct kgsl_submit_commands)

struct kgsl_device_constraint {
	unsigned int type;
	unsigned int context_id;
	void *data;
	size_t size;
};

#define KGSL_CONSTRAINT_NONE 0
#define KGSL_CONSTRAINT_PWRLEVEL 1

#define KGSL_CONSTRAINT_PWR_MIN    0
#define KGSL_CONSTRAINT_PWR_MAX    1

struct kgsl_device_constraint_pwrlevel {
	unsigned int level;
};


struct kgsl_syncsource_create {
	unsigned int id;
	unsigned int __pad[3];
};

#define IOCTL_KGSL_SYNCSOURCE_CREATE \
	_IOWR(KGSL_IOC_TYPE, 0x40, struct kgsl_syncsource_create)


struct kgsl_syncsource_destroy {
	unsigned int id;
	unsigned int __pad[3];
};

#define IOCTL_KGSL_SYNCSOURCE_DESTROY \
	_IOWR(KGSL_IOC_TYPE, 0x41, struct kgsl_syncsource_destroy)

struct kgsl_syncsource_create_fence {
	unsigned int id;
	int fence_fd;
	unsigned int __pad[4];
};

#define IOCTL_KGSL_SYNCSOURCE_CREATE_FENCE \
	_IOWR(KGSL_IOC_TYPE, 0x42, struct kgsl_syncsource_create_fence)

struct kgsl_syncsource_signal_fence {
	unsigned int id;
	int fence_fd;
	unsigned int __pad[4];
};

#define IOCTL_KGSL_SYNCSOURCE_SIGNAL_FENCE \
	_IOWR(KGSL_IOC_TYPE, 0x43, struct kgsl_syncsource_signal_fence)

#endif 
