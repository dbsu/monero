#!/bin/bash -e

export LD_LIBRARY_PATH=${SNAP_LIBRARY_PATH}:${SNAP}/usr/lib/x86_64-linux-gnu
export HOME=${SNAP_DATA}
cd ${SNAP_DATA}

ARGS=
if [ -e "${SNAP_DATA}/etc/singularityd.conf" ]; then
	ARGS="--config-file ${SNAP_DATA}/etc/singularityd.conf"
fi

exec ${SNAP}/bin/singularityd --detach $ARGS
