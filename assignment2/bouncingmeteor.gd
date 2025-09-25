extends Area2D

signal explode

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	$CollisionShape2D.set_deferred("disabled", false)
	
		

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	pass
	


func _on_area_entered(area: Area2D) -> void:
	explode.emit()
	#emit_signal("explode", self)


func _on_bouncing_sprite_hit_edge() -> void:
	$BouncingSprite.velocity*=1.1
