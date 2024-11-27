#include "Factory.h"
#include "Unity.h"

Tool* Factory(std::string tool) {
Tool* ret=0;

// if (tool=="Type") tool=new Type;
if (tool=="Configuration") ret=new Configuration;
if (tool=="FileWriter") ret=new FileWriter;
if (tool=="JobManager") ret=new JobManager;
if (tool=="Monitoring") ret=new Monitoring;
if (tool=="MPMTfakeTrigger") ret=new MPMTfakeTrigger;
if (tool=="MPMT") ret=new MPMT;
if (tool=="RunControl") ret=new RunControl;
if (tool=="SlaveRunControl") ret=new SlaveRunControl;
return ret;
}
