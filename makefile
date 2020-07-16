main: swig python_dist

python_dist:
	python3 setup.py build_ext --inplace

swig:
	swig -c++ -python router.i