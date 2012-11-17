#from distutils.cmd import Command
from setuptools import setup
#from distutils.util import split_quoted
from distutils.extension import Extension
#from distutils.msvccompiler import MSVCCompiler
#from distutils.command.build_ext import build_ext
from Cython.Distutils import build_ext
linkqueue_ext = Extension("linkqueue", ["queue.pyx", "linkqueue.c"])

#ubasic_ext.sources.insert(0, 'ubasic.pyx')

setup(
    name='linkqueue',
    version='0.0.1',
    author='Li Meng Jun',
    author_email='lmjubuntu@gmail.com',
    ext_modules=[linkqueue_ext],
    cmdclass={'build_ext': build_ext},
)
