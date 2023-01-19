/*#
 *#Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *#
 *#SPDX-License-Identifier: BSD-2-Clause
  #*/


/*- from 'global-endpoint.template.c' import allocate_cap with context -*/

/*- set nodes = set() -*/
/*- for end in me.parent.from_ends -*/
    /*- do nodes.add(render_state.label_node_map[end.instance.name]) -*/
/*- endfor -*/

/*- for end in me.parent.to_ends -*/
    /*- do nodes.add(render_state.label_node_map[end.instance.name]) -*/
/*- endfor -*/

/*- set multicore = len(nodes) > 1 -*/


/*- do allocate_cap(me, is_reader=True, multicore=multicore) -*/
/*- if multicore -*/
/*- set (notification, irq) = pop('notification') -*/
/*- set badge = pop('badge') -*/

/*# This is only used for seL4GlobalAsynchCallback #*/
/*- do stash('callback_notification', notification) -*/

seL4_CPtr /*? me.interface.name ?*/_notification(void) {
    return /*? notification ?*/;
}

seL4_Word /*? me.interface.name ?*/_notification_badge(void) {
    return /*? badge ?*/;
}
void /*? me.interface.name ?*/_notification_ack(void) {
    seL4_IRQHandler_Ack(/*? irq ?*/);
}


/*- else -*/
/*- set notification = pop('notification') -*/
/*- set badge = pop('badge') -*/

/*# This is only used for seL4GlobalAsynchCallback #*/
/*- do stash('callback_notification', notification) -*/

seL4_CPtr /*? me.interface.name ?*/_notification(void) {
    return /*? notification ?*/;
}

seL4_Word /*? me.interface.name ?*/_notification_badge(void) {
    return /*? badge ?*/;
}

void /*? me.interface.name ?*/_notification_ack(void) {

}

/*- endif -*/
