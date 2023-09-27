from distutils.core import setup, Extension

module1 = Extension('c_rand',
                    sources = ['c_rand.c', 'random.c'])

setup (name = 'c_rand',
       version = '1.0',
       description = 'c_rand moudle',
       ext_modules = [module1])
