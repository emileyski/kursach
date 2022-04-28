using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class playerController : MonoBehaviour
{
    public int life_count;
    Animator animator;
    private Rigidbody2D rb;

    private GameObject weapon;

    private Joystick joystick;
    [SerializeField]
    private float speed;
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
        joystick = GameObject.Find("Fixed Joystick").GetComponent<Joystick>();
        weapon = transform.Find("Weapon").gameObject;
    }

    void Update()
    {
        PlayerAnimation();
        transform.position += new Vector3(speed * Time.deltaTime * joystick.Horizontal, speed * Time.deltaTime * joystick.Vertical, 0f);
        if (joystick.Horizontal != 0)
            transform.localScale = (joystick.Horizontal > 0) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
    }

    void PlayerAnimation()
    {
        bool isRunning = (joystick.Horizontal != 0 || joystick.Vertical != 0) ? true : false;
        animator.SetBool("isRunning", isRunning);
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.layer == 8)
        {
            life_count--;
            if (life_count <= 0)
                SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
        }
        if (collision.tag == "currentRoom")
        {
            collision.GetComponentInParent<roomParameters>().activation();
        }
    }
    public void shooting(bool isShoot)
    {
        weapon.GetComponent<weaponController>().attack(isShoot);
    }
    private void GettingHit()
    {

    }
}
