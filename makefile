main: swig_placer swig_router swig python_dist

python_dist:
	python3 setup.py build_ext --inplace

swig_placer:
	swig -c++ -python placer.i

swig_router:
	swig -c++ -python router.i

swig:
	swig -c++ -python place_and_route.i