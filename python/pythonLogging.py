#!/usr/bin/python
import logging
import time
import signal
logging.basicConfig(level=logging.ERROR)
logger = logging.getLogger(__name__)

def handler1(signum, frame):
   logger.setLevel(logging.DEBUG)

def handler2(signum, frame):
   logger.setLevel(logging.INFO)

signal.signal(signal.SIGUSR1, handler1)
signal.signal(signal.SIGUSR2, handler2)
while True:
   logger.info('info logging')
   logger.debug('debug logging')
   logger.error('error logging')
   logger.warn('warn logging')
   time.sleep(2)
