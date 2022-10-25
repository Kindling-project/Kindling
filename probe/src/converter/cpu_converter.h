#ifndef CPU_CONVERTER_H
#define CPU_CONVERTER_H
#include <string>
#include <map>
#include "sinsp.h"
#include "cgo/kindling.h"
class cpu_data {
public:
    uint64_t start_time;
    uint64_t end_time;
    uint64_t on_total_time;
    uint64_t off_total_time;
    string time_specs;
    string runq_latency;
    string time_type;
    uint32_t tid;
};

class cpu_converter
{
public:
    cpu_converter(sinsp *inspector);
    ~cpu_converter();

    int convert(kindling_event_t_for_go *p_kindling_event, sinsp_evt *evt, vector<QObject *> qls);

    bool Cache(sinsp_evt *evt);
private:
    int init_kindling_event(kindling_event_t_for_go *p_kindling_event, sinsp_evt *sevt);

    int add_threadinfo(kindling_event_t_for_go *p_kindling_event, sinsp_evt *sevt);

    int add_cpu_data(kindling_event_t_for_go *p_kindling_event, sinsp_evt *sevt, vector<QObject *> qls);

    int32_t set_boot_time(uint64_t *boot_time);

    sinsp *m_inspector;

    uint64_t sample_interval;
};

#endif //CPU_CONVERTER_H
