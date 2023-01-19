/*#
 *#Copyright 2017, Data61, CSIRO (ABN 41 687 119 230)
 *#
 *#SPDX-License-Identifier: BSD-2-Clause
  #*/

#include <sel4/sel4.h>
/*- from 'global-endpoint.template.c' import allocate_cap with context -*/

/*? macros.show_includes(me.instance.type.includes) ?*/

/*- set nodes = set() -*/
/*- for end in me.parent.from_ends -*/
    /*- do nodes.add(render_state.label_node_map[end.instance.name]) -*/
/*- endfor -*/

/*- for end in me.parent.to_ends -*/
    /*- do nodes.add(render_state.label_node_map[end.instance.name]) -*/
/*- endfor -*/

/*- set multicore = len(nodes) > 1 -*/



/*- for c in me.parent.to_ends -*/
    /*- do allocate_cap(c, is_reader=False, multicore=multicore) -*/
    /*- if multicore -*/
    void /*? me.interface.name ?*/_emit_underlying(void) {
        /*- set (notification, sgi, node_id) = pop('notification') -*/

        seL4_ARM_SGI_Signal_Generate(/*? notification ?*/, /*? sgi ?*/, 1lu <<(/*? node_id ?*/));
    }
    /*- else -*/

    /*- set notification = pop('notification') -*/

    void /*? me.interface.name ?*/_emit_underlying(void) {
        seL4_Signal(/*? notification ?*/);
    }
    /*- endif -*/
/*- endfor -*/
