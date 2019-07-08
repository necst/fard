# (c) copyright by Politecnico di Milano
# original authors: Samuele Barbieri, Fabiola Casasopra, Rolando Brondolin
#
# fard_event.py
# This file contains classes to define events and their behavior

#
# FardEvent
# This class should be extended by all the events used by a FardTask. This class
# provides two methods: fire() and handle(). fire is used within the user code
# to launch an event to one task, a group of tasks or the entire application.
# handle() instead is used to receive the event, and should be reimplemented in
# the subclasses.
#
class FardEvent():

    # FardEvent constructor
    # Should be reimplemented if other methods or configurations are to be added
    # inside the subclass.
    def __init__(self):
        pass

    # fire()
    # method used to send en event to other tasks in the application.
    # fire() can send data to a specific peer, to a group of peers identified by
    # the task name and to the whole application, depending on the input
    # parameters. If nothing is specified, the message is sent to the whole
    # application. If task is specified, the message is sent to the proper
    # group of peers depending on their task type. If the peer is specified, the
    # message is sent to the associated peer. If auto_send is set to true,
    # the system sends the data also to the node that launched the event, if it
    # is in the same application, task or if the peer id matches the sender.
    # content is the message body, which can be any python object
    def fire(self, task=None, peer=None, content="", auto_send=False):
        if task!=None and peer!=None:
            raise Exception('Please specify just task or peer')
        elif peer!=None:
            self.network_manager.send_message(peer, str(type(self).__name__), content, auto_send)
        elif task!=None:
            self.network_manager.send_task_message(task, str(type(self).__name__), content, auto_send)
        elif peer==None and task==None:
            self.network_manager.send_group_message(str(type(self).__name__), content, auto_send)

    # handle()
    # this method should be reimplemented by the subclasses and it is called by
    # the system when an event of this type arrives to the task.
    # content here is of type FardNetworkData and provides data about the sender
    # as well as the message itself.
    def handle(self, content):
        pass

    # event_registered()
    # this method is called internally when the event is registered within the
    # task on setup. This allows to connect the event with the network to
    # properly send messages.
    def event_registered(self, network_manager):
        self.network_manager = network_manager
