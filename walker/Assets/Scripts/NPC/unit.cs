using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class unit : MonoBehaviour
{
    [SerializeField]
    protected int lifeCount;

    private roomParameters currentRoom;

    protected NavMeshAgent agent;
    //до обновлений;
    protected GameObject player;
    protected Animator animator;
    [SerializeField] protected float atackRange;
    protected bool isActivated = false, atacking = false;
    protected virtual void Start()
    {
        animator = GetComponent<Animator>();
        agent = GetComponent<NavMeshAgent>();
        player = GameObject.Find("Player");
        agent.updateRotation = false;
        agent.updateUpAxis = false;

    }
    public virtual void activation()
    {
        animator.SetTrigger("isActivated");
        isActivated = true;
    }
    // Update is called once per frame
    protected virtual void Update()
    {
        unit_moveing();
    }
    protected virtual void unit_moveing()
    {
        if (isActivated && !atacking)
        {
            agent.SetDestination(player.transform.position);
            bool x = (Vector3.Distance(transform.position, player.transform.position) < atackRange) ? true : false;
            if (x && !atacking)
            {
                StartCoroutine("Atack");
            }
            transform.localScale = (player.transform.position.x > transform.position.x) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
        }
    }
    //do izmeneniy
    protected virtual IEnumerator Atack()
    {
        if (isActivated)
        {
            atacking = true;
            animator.SetBool("IsAttacking", true);
            yield return new WaitForSeconds(0.45f);
            animator.SetBool("IsAttacking", false);
            yield return new WaitForSeconds(1.5f);
            atacking = false;
        }
    }
    protected virtual void die()
    {
        animator.SetTrigger("isDied");
        isActivated = false;
        agent.SetDestination(transform.position);
        transform.Find("Weapon").gameObject.SetActive(false);
        GetComponent<CapsuleCollider2D>().enabled = false;
        currentRoom.someUnitIsZdoh();
    }
    protected virtual void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.GetComponent<weaponController>())
        {
            lifeCount -= collision.GetComponent<weaponController>().damageCount;
            if (lifeCount <= 0)
            {
                die();
            }
        }
        if (collision.GetComponentInParent<roomParameters>())
        {
            currentRoom = collision.GetComponentInParent<roomParameters>();
            unit[] x = currentRoom.unitsInRoom;
            currentRoom.unitsInRoom = new unit[currentRoom.unitsInRoom.Length + 1];
            for(int i = 0; i < currentRoom.unitsInRoom.Length - 1; i++)
            {
                currentRoom.unitsInRoom[i] = x[i];
            }
            currentRoom.unitsInRoom[currentRoom.unitsInRoom.Length - 1] = gameObject.GetComponent<unit>();
        }
    }
}
