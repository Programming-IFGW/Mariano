import numpy as np

#################### CLASSES
####################

class Object():
    def __init__(self, pos_in, vel_in, radius, mass):
        self.pos = np.array(pos_in)
        self.vel = vel_in
        self.m = mass
        self.r = radius

class World():
    def __init__(self, obj_set, external_forces):
        self.obj = obj_set
        self.ext_forces = external_forces

dt = 0.01

##################### AUX. FUNCTIONS
#####################
def update(obj,force):
    ac = force/obj.m
    pos_old = obj.pos
    obj.pos = obj.pos+obj.vel*dt +ac*dt**2/2
    obj.vel = obj.vel+ac*dt
    if(obj.pos[1]<0):
        obj.vel[1] = -obj.vel[1]*0.95
        obj.pos = pos_old

def run(world):
    id_this = 0
    id_other = 0
    for myobj in world.obj:
        id_this = id_this + 1
        for otherobj in world.obj:
            id_other = id_other + 1
            if(id_this != id_other):
                if( np.linalg.norm(myobj.pos-otherobj.pos) < (myobj.r+otherobj.r)):
                    v1i = myobj.vel
                    v2i = otherobj.vel
                    m1 = myobj.m
                    m2 = otherobj.m


                    myobj.vel = (v1i*(m1-m2)+2*v2i*m2)/(m1+m2)
                    otherobj.vel = (v2i*(m2-m1)+2*v2i*m1)/(m1+m2)

        update(myobj, world.ext_forces*myobj.m)
    return 0

##################### INPUTS
#####################
pos_0 = np.array([0, 0]) #m
vel_0 = np.array([10, 10]) #m
r0 = 0.1
m0 = 0.1 #kg

pos_1 = np.array([20, 0.0]) #m
vel_1 = np.array([-10, 10]) #m
r1 = 0.1
m1 = 0.1 #kg

g = np.array([0, -9.8]) #m/s²

##################### TESTS
#####################

obj_test = [Object(pos_0, vel_0, r0, m0), Object(pos_1, vel_1, r1, m1)]
world_test = World(obj_test, g)

pos_x_hist1 = []
pos_y_hist1 = []
vel_hist1 = []

pos_x_hist2 = []
pos_y_hist2 = []
vel_hist2 = []

##################### SIMULATIONS
#####################

num_steps = 1000

for t in range(num_steps):
    pos_x_hist1.append(obj_test[0].pos[0])
    pos_y_hist1.append(obj_test[0].pos[1])
    vel_hist1.append(obj_test[0].vel[1])

    pos_x_hist2.append(obj_test[1].pos[0])
    pos_y_hist2.append(obj_test[1].pos[1])
    vel_hist2.append(obj_test[1].vel[1])
    run(world_test)



import matplotlib.pyplot as plt

fig, ax = plt.subplots(1,2, figsize=(6,3))

time = np.linspace(0,num_steps*dt,num_steps)

ax[0].plot(pos_x_hist1, pos_y_hist1)
ax[1].plot(time, vel_hist1)

ax[0].plot(pos_x_hist2, pos_y_hist2)
ax[1].plot(time, vel_hist2)

plt.show()





