#!/bin/bash -e

exec tail -c +0 -F ${SNAP_DATA}/.bitsingularity/bitsingularity.log
