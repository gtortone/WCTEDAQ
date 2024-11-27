#!/bin/bash

Dependencies=`pwd`/Dependencies

export LD_LIBRARY_PATH=`pwd`/lib:${Dependencies}/ToolFrameworkCore/lib:${Dependencies}/ToolDAQFramework/lib:${Dependencies}/libDAQInterface/lib:$LD_LIBRARY_PATH

export SEGFAULT_SIGNALS="all"
