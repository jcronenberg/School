extends VBoxContainer


var stack_instances: Array = []
var stack_counter: int = 0
var stack_size = 0

func _ready():
	pass

func spawn_stack(size: int):
	# Set global stack_size
	stack_size = size;
	
	# Load the element scene to spawn them
	var element_scene = load("res://StackElement.tscn")
	
	# Spawn size amount of elements and store the instances in stack_instances array
	# Unfortunately this will spawn them in the reverse order, meaning that
	# the first stack element will be the last instance in the stack_instances array
	# Be careful to account for that
	for i in range(0, size):
		stack_instances.append(element_scene.instance())
		self.add_child(stack_instances[i])
	pass

func draw_push(element: int):
	# Calculate instance_id
	var instance_id = stack_size - 1 - stack_counter

	# set color and text for instance
	stack_instances[instance_id].get_node("ColorRect").color = Color(0, 1, 0)
	stack_instances[instance_id].get_node("ColorRect/Label").text = str(element)

	# advance stack_counter
	stack_counter += 1

func draw_pop():
	# Calculate instance_id
	var instance_id = stack_size - stack_counter;

	# set color and text for instance
	stack_instances[instance_id].get_node("ColorRect").color = Color(1, 0, 0)
	stack_instances[instance_id].get_node("ColorRect/Label").text = ""

	# advance stack_counter
	stack_counter -= 1
