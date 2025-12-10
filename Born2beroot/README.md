*This project has been created as part of the 42 curriculum by wgan.*

## Description 
The aim of this project is to showcase and explain how to setup a Debian virtual machine using Oracle VirtualBox to show how virtualization works through creating and configuring a VM VirtualBox, how a VM simulates hardware, CPU, RAM, storage, and networking —and how an operating system can run independently inside a host system.

The process involves:
- Installing VirtualBox and downloading a Debian ISO.
- Creating a VM, assigning virtual resources, and selecting Debian as the guest OS.
- Configuring virtual hardware, such as networking and storage.
- Installing Debian inside the VM, demonstrating how the OS treats virtualized components as real hardware.

The learning and evaluation outcomes include:
- How OS installation works in a sandboxed environment
- Better understanding of Linux Operating Systems, Security Kernels, and Firewalls
- Practical Linux administration and hands-on learning on how to navigate and interact with the VM with the related packages and tools
- General security practices and having good password policies

## Project description
The following tables aims to showcase the main design choices made when selecting which operating system to use during setup, as well as the comparison between the related tools and technologies being implemented in this project:

### Operating system
| | *Debian | Rocky Linux |
| ----- | ----- | ----- |
| Design | Open-source | Enterprise-grade |
| Performance | Suitable for various applications | Optimized for enterprise workloads |
| Security Framework | AppArmor | SELinux |
| Customizability | Highly customizable according to user needs | Less customizable, with more focus on stability |
| Usage | Versatility ranges from servers to desktops | Ideal for enterprises and servers |

**Debian 13(trixie) as the choice of OS mostly because of its versatility, and is recommended given the scale of the project*

### Linux Security Module
| | *AppArmor | SELinux |
| ----- | ----- | ----- |
| Security Model | Path-based access control | Label-based access control |
| Complexity | Easier to configure | Complex policies |
| Default in | Debian / Ubuntu | RHEL / Rocky / Fedora |
| Policy Management | Based on file paths, more intuitive | Based on security context and labels, harder to debug |
| Customizability | Highly customizable according to user needs | Less customizable, with more focus on stability |

**AppArmor was chosen for its simplicity and ease of configuration and management, as well as having path-based access control which is more intuitive due to the familiarity of traditional unix permissions*

### Firewall
| | *UFW (Uncomplicated FireWall) | Firewalld |
| ----- | ----- | ----- |
| Application | Simple deployments & small webs servers | Enterprise-level & multi-interface networks |
| Complexity | Easy to use and beginner friendly | More complex and steeper learning curve |
| Dynamic rule updates | No (reload flushes connections) | Yes |
| Kernel Dependency | Minimal | High but modern |

**UFW was chosen as it is beginner friendly and allows for simple deployments which is sufficient for this project*

### Virtualization tool
| | *Oracle VirtualBox | UTM |
| ----- | ----- | ----- |
| Technology | Hypervisor developed by Oracle | Wrapper + frontend for QEMU |
| Primary Architecture Support | Optimized for x86-64 hardware with no emulation overhead | ARM64 (Apple Silicon), x86/AMD64 |
| Platform support | Windows, macOS (Intel), Linux | macOS (Intel + Apple Silicon), iOS/iPad (limited) |
| General use cases | Cross-platform desktop VMs on x86; dev / test environments | Apple Silicon (ARM) devices, sandboxed systems, iOS experimentation |

**Oracle VirtualBox was chosen for this project, as UTM is not supported in linux-based systems*

## Instructions
Navigate through the applications menu and run the Oracle VirtuaBox application; This will open up the Oracle VM VirtualBox Manager. 
Before proceeding, compare the signature of the VM instance with the signature found in the git repository. This can be done by writing the following line of code below:

    sha1sum <filename>.vdi
If the signatures match, then proceed by cloning the VM (deleting any previous clones of the VM); this step is crucial to ensure the signature of the original VM remains unchanged.
After cloning is complete, proceed by clicking start to boot up the VM. (Double check and make sure you boot up the clone and not the original VM) 
Once everything is set up and the VM is running, follow the instructions listed on the evaluation sheet and start the evaluation.

### Commands for execution
Check if a service is active / running:

    sudo systemctl status <service>
Check if a program is properly installed in the VM:

    dpkg -l | grep <program>
Check partitions for your VM:
    
    lsblk
Add a new user:

    sudo adduser <newname>
Add a new group:

    sudo groupadd <newgroup>
Get all users belonging to a group:

    getent group <groupname>
Check all groups a user belongs to:

    groups <name>
Modify the hostname:

    hostnamectl set-hostname <newhostname>
Change password of selected user:

    passwd <username>
## Resources
The links listed in order below contains additional resources related to this project for reference:

- AppArmor vs. SELinux - https://tuxcare.com/blog/selinux-vs-apparmor/
- Cron scheduler - https://www.cbtnuggets.com/blog/technology/system-admin/how-to-use-cron-crontabs-to-schedule-linux-jobs
- Debian Package Management - https://www.linuxjournal.com/content/debian-package-management-aptitude-vs-apt-get-ubuntu
- Gitbook tutorial - https://42-cursus.gitbook.io/guide/1-rank-01/born2beroot
- Linux Password policies and enforcement - https://labex.io/tutorials/linux-how-to-enforce-password-complexity-policies-in-linux-414805
- Linux users and groups - https://runcloud.io/blog/linux-users-groups-ubuntu
- Sudo and root privileges - https://medium.com/@kshakirat0/demystifying-the-difference-between-sudo-and-root-in-linux-9ac4c4ea3f86
- Video on setting up a Debian server - https://www.youtube.com/watch?v=s2eM7L_etzo
