#!/bin/bash

echo "PermitRootLogin yes" >> /etc/ssh/sshd_config
service ssh restart

passwd <<EOF
123
123
EOF

exit 0