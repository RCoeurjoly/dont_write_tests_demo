# -*- coding: utf-8 -*-
from hypothesis import given
from hamcrest import assert_that, equal_to
from hypothesis.strategies import integers
from queuecpy import PyQueue

test_counter = 0

@given(integers(1, 100), integers(1, 100))
def test_queue(queue_size, inserted_element):
    global test_counter
    my_queue = PyQueue(queue_size)
    for i in xrange(0, queue_size):
        my_queue.putElement(inserted_element)
        my_queue.getElement()
    my_queue.putElement(inserted_element)
    assert_that(my_queue.getSize(), equal_to(1))
    test_counter += 1
    print(str(test_counter)
          + " tests executed successfully!. Using "
          + str(queue_size) + " as queue size and "
          + str(inserted_element) + " as inserted element")

test_queue()
