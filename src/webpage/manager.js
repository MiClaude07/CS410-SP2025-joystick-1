import * as THREE from "https://unpkg.com/three@latest/build/three.module.js";
import { OrbitControls } from "https://unpkg.com/three@latest/examples/jsm/controls/OrbitControls.js"; 
import { STLLoader } from 'https://unpkg.com/three@latest/examples/jsm/loaders/STLLoader.js';
import { Controller } from './controller.js'


// Manager object to keep track of THREE.js scene
const Manager = (() => {
    console.log("Manager");
    let renderer, control, scene, camera, group, leftStickPadMesh, rightStickPadMesh, leftButton, rightButton;
    let BASE_X_LEFTTHUMB = -3.7;
    let BASE_X_RIGHTTHUMB = 3.7;
    let BASE_Y_THUMB = 2.25
    group = new THREE.Group();
    let controller = Controller;
    controller.init();
    console.log(controller);
    function init() {
        // Create THREE Scene
        scene = new THREE.Scene();
        scene.background = new THREE.Color().setHex(0xAAAAAA);
        scene.add(group);
        group.rotation.x = - Math.PI/8;

        // setup the camera
        let fov = 75;
        let ratio = window.innerWidth/ window.innerHeight;
        var zNear = 0.1;
        let zFar = 10000;
        camera = new THREE.PerspectiveCamera(fov, ratio, zNear, zFar);
        camera.position.set(0, 0, 10);

        // create renderer and add canvas to DOM
        renderer = new THREE.WebGLRenderer({antialias: true});
        renderer.setSize(window.innerWidth, window.innerHeight);
        document.body.appendChild(renderer.domElement);

        // Controls setup
        control = new OrbitControls(camera, renderer.domElement);
        renderer.domElement.onmouseup = function() {
            control.enabled = true;
        }

        //setup lights
        let ambientLight = new THREE.AmbientLight();
        scene.add(ambientLight);

        let light = new THREE.DirectionalLight(0xffffff, 5.0);
        light.position.set(10, 100, 100);
        scene.add(light);
        loadController();
        createStickPadMeshes();
        createButtonMeshes();
        console.log("Init complete");
    };
    function createStickPadMeshes() {
        let geometry = new THREE.SphereGeometry(0.7, 32, 16, 0, 7, 0, 1.3);
        let leftMaterial = new THREE.MeshStandardMaterial({ color: 0x000000});
        leftStickPadMesh = new THREE.Mesh(geometry, leftMaterial);
        leftStickPadMesh.position.z = 0.75
        leftStickPadMesh.rotateX(Math.PI / 2);
        leftStickPadMesh.material.side = THREE.DoubleSide;
        group.add(leftStickPadMesh);

        let rightMaterial = new THREE.MeshStandardMaterial({ color: 0x000000});
        rightStickPadMesh = new THREE.Mesh(geometry, rightMaterial);
        rightStickPadMesh.position.z = 0.75;
        rightStickPadMesh.rotateX(Math.PI / 2);
        rightStickPadMesh.material.side = THREE.DoubleSide;
        group.add(rightStickPadMesh);
    };
    function createButtonMeshes() {
        let geometry = new THREE.CylinderGeometry(0.5, 0.5, 0.5);
        let leftMaterial = new THREE.MeshStandardMaterial({ color: 0x000000});
        leftButton = new THREE.Mesh(geometry, leftMaterial);
        leftButton.rotateX(Math.PI /2);
        leftButton.position.set(-2.45, 0.6, 0.75);
        group.add(leftButton);

        let rightMaterial = new THREE.MeshStandardMaterial({ color: 0x000000});
        rightButton = new THREE.Mesh(geometry, rightMaterial);
        rightButton.rotateX(Math.PI /2);
        rightButton.position.set(2.35, 0.6, 0.75);
        group.add(rightButton);
    };
    function loadController() {
        let loader = new STLLoader();
        loader.load('./assets/controller_no_plate.stl', function (stl) {
            let material = new THREE.MeshStandardMaterial({ color: 0xFF0000});
            let mesh = new THREE.Mesh(stl, material);
            mesh.scale.set(0.07, 0.07, 0.07);
            mesh.rotateZ(Math.PI / 2);
            stl.center();
            group.add(mesh);
        });
    };
    function animateSticks() {
        let leftxpos = controller.getLeftX() / 2;
        let leftypos = controller.getLeftY() / 2;
        let rightxpos = controller.getRightX() / 2;
        let rightypos = controller.getRightY() / 2;
        leftStickPadMesh.position.x = BASE_X_LEFTTHUMB + leftxpos;
        leftStickPadMesh.position.y = BASE_Y_THUMB + leftypos;
        rightStickPadMesh.position.x = BASE_X_RIGHTTHUMB + rightxpos;
        rightStickPadMesh.position.y = BASE_Y_THUMB  + rightypos;
    }
    function animate() {
        group.rotation.y += 0.001;
        if (controller.isButton1Pressed()) {
            leftButton.material.color.setHex(0x00FF00);
        } else {
            leftButton.material.color.setHex(0x000000);
        }
        if (controller.isButton2Pressed()) {
            rightButton.material.color.setHex(0x00FF00);
        } else {
            rightButton.material.color.setHex(0x000000);
        }
        if (controller.isButton3Pressed()) {
            leftStickPadMesh.material.color.setHex(0x00FF00);
        } else {
            leftStickPadMesh.material.color.setHex(0x000000);
        }
        if (controller.isButton4Pressed()) {
            rightStickPadMesh.material.color.setHex(0x00FF00);
        } else {
            rightStickPadMesh.material.color.setHex(0x000000);
        }
        animateSticks();
        renderer.render(scene, camera);
    };
    return {
        init,
        animate
    }
})();

export { Manager };